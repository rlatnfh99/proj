void main(void *arg)
{
	int fail_count;
	int recovery_count;
	int wait_time=50;
	int fail_print_cnt=0;
	char dst_addr_str[80];
	unsigned int dst_addr;
	int user_interval;
	int user_retry_count;
	int user_recovery_time;
	pingstat stat;

	fail_count=0;
	recovery_count=0;
	thread_setMyTid( &dvapc_tinfo, "RPNG" ); 	/* APC-692 */
	
	while(1) {
		int enable;
		int ping_count;
		int delay_msec;
		int interval_msec;
		int quite_mode;
		int alarm_enable;

		/* update network_monitor structure */
		apc_network_monitor_row_get( 1, &network_monitor);
		enable = network_monitor.enable;
		ping_count = network_monitor.ping_count;
		delay_msec = network_monitor.ping_delay_ms;
		interval_msec = network_monitor.ping_interval_ms;
		quite_mode = !(network_monitor.quite_mode);
		alarm_enable = network_monitor.alarm_enable;

		printf("enable = %d\n",enable);
		printf("ping_count = %d\n",ping_count); 
		printf("delay_msec = %dmsec\n",delay_msec); 
		printf("interval_msec = %dmsec\n",interval_msec);
		printf("quite_mode = %d\n",quite_mode);
		printf("alarm_enable = %dsec \n",alarm_enable); 

		router_ping_reset();

		strcpy(dst_addr_str, get_network_monitor_ipaddr_str());
		printf("dst_addr_str = %s \n",dst_addr_str); 
		dst_addr = get_network_monitor_ipaddr();
		printf("dst_addr_str = %u \n",dst_addr); 

		user_interval = get_network_monitor_interval_cnt();
		printf("user_interval = %d \n",user_interval); 
		if (user_interval == 0)	user_interval = 3;

		user_retry_count = get_network_monitor_retry_cnt();
		printf("user_retry_count = %d \n",user_retry_count); 

		user_recovery_time = get_network_monitor_recovery_time();
		printf("user_recovery_time = %d \n",user_recovery_time); 

		if (user_recovery_time<1)	user_recovery_time = user_retry_count;
		task_need_reset = 0;

		while (1) {
			if ( enable ) {
				if (dst_addr != 0) {
					router_ping(dst_addr_str, ping_count, delay_msec, interval_msec, quite_mode, &stat);
					if ( stat.send_count != stat.recv_count ) {
						// no response
						recovery_count = 0;
						if (++fail_count >= user_retry_count) {

							if(fail_print_cnt%20 == 0) dvtr_printf("RTR_PING:Router Link Alarm\n");

							fail_print_cnt++; 

							if (router_link_st != ROUTER_LINK_OFF) {
								router_link_st = ROUTER_LINK_OFF;
								if ( alarm_enable ) {
									davo_alarm(10011, NULL, -1 , NULL, -1, -1, NULL, NULL, "RTR_PING:Router Link Alarm" );
								}

							}
						}

						if ( (fail_count) || (router_link_st == ROUTER_LINK_UNKNOWN) ) {
							wait_time = 0;
						} else {
							wait_time = user_interval*1000;
						}
					} else {
						// recv response
						if(recovery_count == user_recovery_time-1) {
							fail_count=0;
							if (router_link_st != ROUTER_LINK_ON) {
								router_link_st = ROUTER_LINK_ON;
								if ( alarm_enable ) {
									davo_alarm(10010, NULL, -1 , NULL, -1, -1, NULL, NULL, "RTR_PING:Router Link Normal" );
								}
								dvtr_printf("RTR_PING:Router Link Normal\n");
								fail_print_cnt = 0;
							}

							wait_time = user_interval*1000;
						} else if (recovery_count > user_recovery_time-1) {
							wait_time = user_interval*1000;
						} else {
							recovery_count++;
							wait_time = 1000;
						}
					}
				} else { 
					/* no polling address */
					if(recovery_count == user_recovery_time) {
						fail_count=0;
						if (router_link_st != ROUTER_LINK_ON) {
							router_link_st = ROUTER_LINK_ON;
							if ( alarm_enable ) {
								davo_alarm(10010, NULL, -1 , NULL, -1, -1, NULL, NULL, "RTR_PING:Router Link Normal" );
							}
							dvtr_printf("RTR_PING:Router Link Normal\n");
							fail_print_cnt = 0;
						}
						recovery_count++;
					} else if (recovery_count > user_recovery_time-1) {
						/* do nothing */
					} else { 
						recovery_count++;
					}
					wait_time = 1000;
				}
			}
			if ( task_need_reset )	break;
			sleep_task(wait_time);
		}
	}
}

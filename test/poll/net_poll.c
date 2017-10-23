#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/syscall.h>
#include <asm/unistd.h>


#define THREAD_MUTEX pthread_mutex_t
#define THREAD_RWLOCK pthread_rwlock_t
#define MAX_NUM_THREAD 100
#define ROUTER_LINK_UNKNOWN 0
#define ROUTER_LINK_OFF     1
#define ROUTER_LINK_ON      2
#define FALSE 0
#define TRUE  1
extern int h_errno;
typedef enum{
    DNS_SUCCESS             = 0, 
    DNS_WAN_IP_INVAILID     , 
    DNS_NOT_FOUND           , 
    DNS_NO_ADDRESS          , 
    DNS_NO_RECOVERY         , 
    DNS_TRY_AGAIN           , 
    DNS_UNKOWN              , 
} DNS_RESULT_TYPE; 

typedef unsigned long HANDLE, *PULONG, DWORD, *PDWORD;
typedef DWORD pthread_t;

typedef struct __network_monitor__ {
    int enable;
    char addrStr[128];
    int retry_cnt;
    int interval_cnt;
    int recovery_time;
    int ping_count;
    int ping_delay_ms;
    int ping_interval_ms;
    int quite_mode;
    int alarm_enable;
} network_monitor_t;

typedef struct __dvpthread_info__ {
#define MAX_THREAD_NAME 50
    char            name[MAX_THREAD_NAME];
    pthread_t       threads;
    pthread_attr_t  attr;
    int             tid;
    int             policy;
    int             stackSize;
    int             used;
} dvpthread_info_t;

typedef struct __pingstat {
    int send_count;
    int recv_count;
} pingstat;


typedef struct __dvpthread1__ {
    THREAD_MUTEX    lock;
    dvpthread_info_t list[MAX_NUM_THREAD];
} dvpthread_t;

extern dvpthread_t dvapc_tinfo;

static int task_need_reset = 0;
static int router_link_st = ROUTER_LINK_UNKNOWN;
network_monitor_t network_monitor;

void set_router_ping_task_reset(int reset)                                                                                                                                                                
{                                                                                                                                                                                                         
    task_need_reset = 1;                                                                                                                                                                                  
}                                                                                                                                                                                                         

int is_router_link_off()                                                                                                                                                                                  
{                                                                                                                                                                                                         
    //if(!strcasecmp((char *)get_C_pollingip_alarm_type(), "USER_ALARM")) return 0;                                                                                                                       

    return(router_link_st != ROUTER_LINK_ON);                                                                                                                                                             
}                                                                                                                                                                                                         

int is_router_link_used()                                                                                                                                                                                 
{                                                                                                                                                                                                         
    return(router_link_st != ROUTER_LINK_UNKNOWN);                                                                                                                                                        

}                                                                                                                                                                                                         

char *get_network_monitor_ipaddr_str(void)                                                                                                                                                                
{                                                                                                                                                                                                         
    return network_monitor.addrStr;                                                                                                                                                                       
}                                                                                                                                                                                                         

void set_network_monitor_ipaddr_str( char *addrStr )                                                                                                                                                      
{                                                                                                                                                                                                         
    if ( addrStr == NULL ) {                                                                                                                                                                              
        return;                                                                                                                                                                                           
    }                                                                                                                                                                                                     
    snprintf( network_monitor.addrStr, sizeof(network_monitor.addrStr), "%s", addrStr );                                                                                                                  
}                                                                                                                                                                                                         

unsigned int dns_gethostaddr(char *name)
{
    struct hostent *hostp;
    struct in_addr addr_in;
    unsigned int ipaddr=0;

    memset(&addr_in, 0, sizeof(int) );
    if ( Checkstripadd(name) ) {
        return ntohl(str2ip( name ));
    }   

    hostp = gethostbyname(name);
    if ( !hostp ) {
        switch(h_errno) {
            case 3     :
                dns_result_log(3);
                break;
            case 4    :
                dns_result_log(4);
                break;
            case 5      :
                dns_result_log(5);
                break;
            case 2 :
            default             :
                dns_result_log(2);
                break;
        }       
        return 0;
    }   
    while ( *hostp->h_addr_list != NULL ) {
        addr_in.s_addr = *(unsigned int *)*hostp->h_addr_list;
        if (1) {
            break;
        }   
        hostp->h_addr_list++;
    }   
    ipaddr = ntohl(addr_in.s_addr);
    return ipaddr;
}   
unsigned int GetHostAddress(char *name) 
{                                                                                                                                                                                                         
    if ((name==0)||(name[0]==0)) {                                                                                                                                                                        
        return(0);                                                                                                                                                                                        
    } 
    return dns_gethostaddr(name);                                                                                                                                                                         
} 

unsigned int get_network_monitor_ipaddr(void)                                                                                                                                                             
{                                                                                                                                                                                                         
    unsigned int ip;                                                                                                                                                                                      

    ip = GetHostAddress(network_monitor.addrStr);                                                                                                                                                         

    return ip;                                                                                                                                                                                            
}                                                                                                                                                                                                         

int get_network_monitor_retry_cnt(void)                                                                                                                                                                   
{                                                                                                                                                                                                         
    return network_monitor.retry_cnt;                                                                                                                                                                     
}                                                                                                                                                                                                         

void set_network_monitor_retry_cnt( int cnt )                                                                                                                                                             
{                                                                                                                                                                                                         
    network_monitor.retry_cnt = cnt;                                                                                                                                                                      
}                                                                                                                                                                                                         

int get_network_monitor_interval_cnt(void)                                                                                                                                                                
{                                                                                                                                                                                                         
    return network_monitor.interval_cnt;                                                                                                                                                                  
}                                                                                            

void set_network_monitor_interval_cnt( int cnt )                                                                                                                                                          
{                                                                                                                                                                                                         
    network_monitor.interval_cnt = cnt;                                                                                                                                                                   
}                                                                                                                                                                                                         
                                                                                                                                                                                                      
int get_network_monitor_recovery_time(void)                                                                                                                                                               
{                                                                                                                                                                                                         
    return network_monitor.recovery_time;                                                                                                                                                                 
}                                                                                                                                                                                                         
                                                                                                                                                                                                      
void set_network_monitor_recovery_time( int time )                                                                                                                                                        
{                                                                                                                                                                                                         
    network_monitor.recovery_time = time;                                                                                                                                                                 
}                                                                                                                                                                                                         

typedef struct __dvpthread__ {
    char name[128];
    int  pid;
} DVPTHREAD_t;

int thread_setMyTid(DVPTHREAD_t *pPid, char *name)
{                                                                                                                                                                                                         
    static int idx=0;                                                                                                                                                                                     
    int pid=0;                                                                                                                                                                                            
#ifdef __PTHREAD_DEBUG                                                                                                                                                                                    
    struct sched_param my_param;                                                                                                                                                                          
    int my_policy;                                                                                                                                                                                        
    int status;                                                                                                                                                                                           
#endif                                                                                                                                                                                                    

    if(pPid == NULL) {                                                                                                                                                                                    
        return (FALSE);                                                                                                                                                                                   
    }                                                                                                                                                                                                     

    pid = (int)syscall(__NR_gettid);                                                                                                                                                                      

#ifdef __PTHREAD_DEBUG                                                                                                                                                                                    

    status = pthread_getschedparam((pthread_t)pthread_self(), &my_policy, &my_param);                                                                                                                     

    if (status!= 0) {                                                                                                                                                                                     
        printf("error at geting sched param\n");                                                                                                                                                          
    }                                                                                                                                                                                                     

    // 읽어온 쓰레드 정보 출력                                                                                                                                                                            

    printf("running at %s / %d\n",                                                                                                                                                                        
            (my_policy == SCHED_FIFO ? "FIFO"                                                                                                                                                             
             : (my_policy == SCHED_RR ? "RR"                                                                                                                                                              
                 : (my_policy == SCHED_OTHER ? "OTHRER"                                                                                                                                                   
                     : "unknown"))),                                                                                                                                                                      
            my_param.sched_priority);                                                                                                                                                                     
#endif                                                                                                                                                                                                    

    if( idx < MAX_NUM_THREAD) {                                                                                                                                                                           
        for( idx = 0 ; idx < MAX_NUM_THREAD; idx++) {                                                                                                                                                     
            if( pPid[idx].pid == 0 ) {                                                                                                                                                                    
                sprintf((char*)pPid[idx].name, "Tid ---> %s, %d\n",name, pid);                                                                                                                            
                pPid[idx].pid = pid;                                                                                                                                                                      
                break;                                                                                                                                                                                    
            }                                                                                                                                                                                             
        }                                                                                                                                                                                                 
        idx++;                                                                                                                                                                                            
    } else {                                                                                                                                                                                              
        printf("%s thread index is out of range\n", (char*)name);                                                                                                                                         
    }                                                                                                                                                                                                     

    return pid;                                                                                                                                                                                           
}                                                                                                                                                                                                         

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

#ifndef __PING_H__
#define __PING_H__

#ifndef __PING_C__
#	undef  EXPORT_FUNCTION
#	define EXPORT_FUNCTION extern
#else
#	undef  EXPORT_FUNCTION
#	define EXPORT_FUNCTION
#endif

typedef struct __pingstat {
	int send_count;
	int recv_count;
} pingstat;

EXPORT_FUNCTION int ping(char *host, int ping_count, int delay_msec, int interval_msec, int quite_mode, pingstat *ps);

EXPORT_FUNCTION void router_ping_reset(void);
EXPORT_FUNCTION int router_ping(char *host, int ping_count, int delay_msec, int interval_msec, int quite_mode, pingstat *ps);
EXPORT_FUNCTION int PingTest( char *pDest, int count, int timeout, int quiet );

#endif	// __PING_H__


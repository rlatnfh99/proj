#include <stdio.h>

#define GET32BIT(src,start,len) ((~(0xFFFFFFFF<<len)) & (src >> (32 - start - len))) 
#define GET16BIT(src,start,len) ((~(0xFFFF<<len)) & (src >> (16 - start - len)))   

unsigned int cwrt_get_32str( int val, int start, int len, char *desc, char *rbuf, int rsize )
{
    unsigned int         rval = 0;
    int         end = start+len-1;
    unsigned int         bits = 0x80000000;
    int         i = 0;
    int         j = 0;

    if ( desc==NULL || rbuf==NULL ) { 
        strcpy(rbuf,"buffer error");
        return rval;
    }   

    if ( start>=32 ) { 
        strcpy(rbuf,"start error");
        return rval;
    }   

    if ( end>=32 ) { 
        strcpy(rbuf,"end error");
        return rval;
    }   

    rval = GET32BIT( val,start,len );

    for(i=0,j=0;i<32;i++,j++) {
        if ( i!=0 && (i%4)==0 ) { 
            rbuf[j] = ' ';
            j++;
        }   
        if ( i>=start && i<=end ) { 
            if ( val & bits ) { 
                rbuf[j] = '1';
            } else {
                rbuf[j] = '0';
            }   
        } else {
            rbuf[j] = '.';
        }   
        bits = bits>>1;

    }   
    snprintf(&rbuf[j],rsize," : %s = 0x%x(%d)",desc,rval,rval);

    return rval;
}


char *cwrt_get_16str( int val, int start, int len, char *desc, char *rbuf, int rsize )
{
    unsigned short rval = 0;
    int         end = start+len-1;
    int         bits = 0x8000;
    int         i = 0;
    int         j = 0;

    if ( desc==NULL || rbuf==NULL ) {
        strcpy(rbuf,"buffer error");
        return NULL;
    }

    if ( start>=16 ) {
        strcpy(rbuf,"start error");
        return NULL;
    }

    if ( end>=16 ) {
        strcpy(rbuf,"end error");
        return NULL;
    }


    rval = GET16BIT( val,start,len );

    for(i=0,j=0;i<16;i++,j++) {
        if ( i!=0 && (i%4)==0 ) {
            rbuf[j] = ' ';
            j++;
        }
        if ( i>=start && i<=end ) {
            if ( val & bits ) {
                rbuf[j] = '1';
            } else {
                rbuf[j] = '0';
            }
        } else {
            rbuf[j] = '.';
        }

        bits = bits>>1;

    }
    snprintf(&rbuf[j],rsize," : %s = 0x%x(%d)",desc,rval,rval);


    return rbuf;
}


int main( void )
{
    int i=0;
    int val=0;
    char rbuf[512];
    unsigned int ret=0;

    ret = cwrt_get_32str( 0x0000000f, 28,2, "capwap preamble", rbuf, sizeof(rbuf) );
    printf("-->[%s]0x%x\n",rbuf,ret);
    return 1;
}


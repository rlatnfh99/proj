#include <stdio.h>

typedef struct k{
    union{
        unsigned char B[16];
        unsigned short w[8];
    }u;
}K;
void main(void)
{
    printf("char               : %d\n",sizeof(char));
    printf("unsigned char      : %d\n",sizeof(unsigned char));
    printf("short              : %d\n",sizeof(short));
    printf("unsigned short     : %d\n",sizeof(unsigned short));
    printf("int                : %d\n",sizeof(int));
    printf("unsiged int        : %d\n",sizeof(unsigned int));
    printf("long               : %d\n",sizeof(long));
    printf("unsigned long      : %d\n",sizeof(unsigned long));
    printf("long long          : %d\n",sizeof(long long));
    printf("unsigned long long : %d\n",sizeof(unsigned long long));
    printf(" in6_addr          : %d\n",sizeof(K));
    return;
}


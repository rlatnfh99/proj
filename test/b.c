#include <stdio.h>

void main (void)
{
    unsigned int a = 0x80000000;
    int b = 0x01;
    int c = 0x80000000;
printf("(unsigned)a : %u |||| (singed)c : %d\n",a,c);
    printf("%x\n",a);
    a = a>>1;
    printf("%x\n",a);
    a = a>>1;
    printf("%x\n",a);
    a = a>>1;
    printf("%x\n",a);
    a = a>>1;
    printf("%x\n",a);
    a = a>>1;
    printf("%x\n",a);
    a = a>>1;
    printf("%x\n",a);
    a = a>>1;
    printf("%x\n",a);

    printf("%x\n",b);
    b = b<<1;
    printf("%x\n",b);
    b = b<<1;
    printf("%x\n",b);
    b = b<<1;
    printf("%x\n",b);
    b = b<<1;
    printf("%x\n",b);
    b = b<<1;
    printf("%x\n",b);
    b = b<<1;
    printf("%x\n",b);
    b = b<<1;
    printf("%x\n",b);
}

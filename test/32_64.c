#include<stdio.h>


#if ( __WORDSIZE == 64 )
    #error 64
#else
    #error 32
#endif



int main(void)
{

    return 0;
}

#include <stdio.h>

void main(void){
    int src;
    int *ptr=0;

    src = 1000;
    ptr = &src;
    printf("src addr : %p\n", &src);
    printf("ptr addr : %p\n", ptr);
    printf("&ptr,,,  : %p\n", &ptr);

}


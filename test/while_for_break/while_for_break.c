#include <stdio.h>

void main( void )
{
    int i, j;
    
    i=0;
    while( i < 10 ){
        for ( j=0; j<30; j++ ){
            if(j = 3){
                printf ("j 는 3이라서for문에서 나온거요");
                break;
            }else{
                continue;
            }
        }
        printf("j가 3이라서 for문에서 나왔지만 while 문에는 영향이 없소[%d]",i);
        i++;
    }
    printf("j가 3이라서 for문에서 나왔고 while 문에서도 나왔소[%d]",i);
}

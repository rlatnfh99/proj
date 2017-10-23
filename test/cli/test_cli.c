#include <stdio.h>



int main(int argc, char *argv[])
{
    int i;
    printf("argc = %d \n",argc);
    for(i = 0; i < argc; i++){
        switch(argv[i]){
            case "mode": 
                printf("argv[%d] Hi my friend\n",i);
            break;

            default: 
            printf("mode 를 입력하세요");
        }


    }
} 

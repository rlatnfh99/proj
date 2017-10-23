#include <stdio.h>

#define MIS -1
#define PLS 1

char *str ( char num ) { 
    switch ( num ) {
        case MIS: return "마이너스 임마";
        default : return "몰라 임마";
    }   
}
struct put_min {
    unsigned char a;

};

void main ( void ) { 
    struct put_min  k;  


    k.a = -1; 
    printf("\nk.a  = (%s)(%x) \n",str(k.a),k.a);
}

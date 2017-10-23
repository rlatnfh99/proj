#include <stdio.h>
#include <string.h>

#pragma pack(push,1)
typedef struct msg0 {
    int type;
    short len;
    char msg[0];
} my_msg0;

typedef struct msg1 {
    int type;
    short len;
    int msg;
} my_msg1;


#if 0
const char message[] = { 
    0x00, 0x00, 0x00, 0x00,
    0x06, 0x00,
    0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x00
};
#endif

#if 0
const char message[] = { 
    0x00, 0x00, 0x00, 0x00,
    0x06, 0x00,
    0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x00,
    0x01, 0x00, 0x00, 0x00,
    0x04, 0x00,
    0x01, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00,
    0x04, 0x00,
    0x02, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00,
    0x04, 0x00,
    0x03, 0x00, 0x00, 0x00,
};
#endif

const char message[] = { 
    0x00, 0x00, 0x00, 0x00,
    0x06, 0x00,
    0x48, 0x65, 0x6c, 0x6c, 0x6f, 0x00,
    0x01, 0x00, 0x00, 0x00,
    0x04, 0x00,
    0x01, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00,
    0x04, 0x00,
    0x02, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00,
    0x04, 0x00,
    0x03, 0x00, 0x00, 0x00,
     0x01, 0x00, 0x00, 0x00,
    0x04, 0x00,
     0xff, 0xff, 0xff, 0xfe,
};

int parse_msg( const char *msg, int len ) 
{
    my_msg0 *ptr0;
    my_msg1 *ptr1;
    char *type; 
    short str_len;
    //int int_msg;
    char *char_msg;
    //    char *get;
    // 실패 return < 0
    // 성공 return == 1
    if ( msg == NULL ) {
        return -1;
    }

    ptr0 = ( my_msg0 *)msg;

    while(1){

        if ( ptr0->type == 0 ) {
            ptr0 = ( my_msg0 *)msg;
            msg += sizeof(ptr0->type);
            str_len = (ptr0->len);
            msg += sizeof(ptr0->len);
            type = "STRING";
            char_msg = &(ptr0->msg[0]);
            msg += str_len;

            if(str_len != (strlen(ptr0->msg)+1)){
                return -3;
            }
            printf ( "====================\n" );
            printf ( "TYP : %s\n", type );
            printf ( "LEN : %d\n", str_len ); 
            printf ( "MSG : %s\n", char_msg);
            printf ( "====================\n" );

            ptr0 = ( my_msg0 *)msg;
        } else if ( ptr0->type == 1 ) {
            ptr1 = ( my_msg1 *)msg;
            msg += sizeof(ptr0->type);
            str_len = (ptr1->len);
            msg += sizeof(ptr1->len);
            type = "INT";
            msg += str_len ;

            printf("%d , %d\n",str_len, strlen(ptr0->msg));
            // if(str_len != strlen(ptr0->msg)+1){
            //     return -3;
            // }
            if(6 == (strlen(ptr0->msg))){
                return -3;
            }

            printf ( "====================\n" );
            printf ( "TYP : %s\n", type );
            printf ( "LEN : %d\n", str_len );
            printf ( "MSG : %d\n", ptr1->msg);
            printf ( "====================\n" );

            ptr0 = ( my_msg0 *)msg;
        }else{
            return -2;
        }

    }

    return 1;
}



int main ( void ) 
{
    int ret;
   
    ret = parse_msg( message, sizeof(message) );
    printf(" parse done. ret %d\n", ret );

    return 0;
}

#pragma pack(pop)

#include <stdio.h>
#include <string.h>

typedef struct __int_str_t__ { 
    int a;
    int b;
    int c;
} int_str_t;

typedef struct __char_str_t__ { 
    char str[12];
} char_str_t;

typedef struct __test_str_t__ { 
    int     a; // 1
    short   b; // 2
    char    c; // 3
    char    d; // 4 
    char    str[4]; // "123"
} test_str_t;
//1
void pointing_test_1( void )
{
    printf("----------pointing_test_1\n");
    printf("test1 size : %d\n", sizeof(int_str_t));
    printf("test2 size : %d\n", sizeof(char_str_t));
}



//2
void pointing_test_2( int_str_t *dest, char_str_t *src )
{
    printf("----------pointing_test_2\n");
    memcpy(dest,src,sizeof(*src));
    printf ( "%x\n",dest->a);
    printf ( "%x\n",dest->b);
    printf ( "%x\n",dest->c);
}


//3
void pointing_test_3( char_str_t *dest, int_str_t *src )
{
    int i;

    printf("----------pointing_test_3\n");
    memcpy(dest,src,sizeof(*src));
    for ( i = 0 ; i < sizeof(*src) ; i++){

        printf ( "%x\n", dest->str[i]);
    }
}

//4
void pointing_test_4( char *dest, void *src, int type )
{
    int i;
    int_str_t   *temp0;
    int_str_t   *int_temp;
    char_str_t  *temp1;
    char_str_t  *char_temp;
    test_str_t  *temp2;
    test_str_t  *test_temp;
    // type == 0 ( int_str_t -> dest )
    printf("----------pointing_test_4\n");
    if ( type == 0 ){
        int_temp = ( int_str_t *) src;
        temp0 =( int_str_t *) dest;

        temp0->a  = int_temp->a; 
        temp0->b  = int_temp->b; 
        temp0->c  = int_temp->c; 

    }

    // type == 1 ( char_str_t -> dest ) 
    if( type == 1 ){
        char_temp = ( char_str_t *) src; 
        temp1 = (char_str_t *) dest;

        for ( i = 0 ; i < sizeof(char_str_t) ; i++){
            printf("char_temp : [%x]\n", char_temp->str[i]);
            temp1->str[i] = char_temp->str[i];
        }
    }

    // type == 2 ( test0_str_t -> dest )
    if( type == 2 ){
        test_temp = ( test_str_t * ) src;
        temp2 = ( test_str_t * ) dest;

        temp2->a = test_temp->a;
        temp2->b = test_temp->b;
        temp2->c = test_temp->c;
        temp2->d= test_temp->d;
        temp2->str[0] = test_temp->str[0];
        temp2->str[1] = test_temp->str[1];
        temp2->str[2] = test_temp->str[2];
        temp2->str[3] = test_temp->str[3];

    }
}

int main ( void )
{
    int_str_t   test1;
    char_str_t  test2;
    char        test3[80];
    test_str_t  test4;
    char        *ptr;
    int         i;

    test1.a = 1;
    test1.b = 2;
    test1.c = 3;

    for ( i=0; i<12; i++ ) { 
        test2.str[i] = i;
    }

    // 1. test1 크기와 test2 크기를 확인. -> 함수 
    pointing_test_1();

    test1.a = 1;
    test1.b = 2;
    test1.c = 3;

    for ( i=0; i<12; i++ ) { 
        test2.str[i] = i;
    }
    // 2. test1에 test2 넣어보기 -> 함수
    pointing_test_2(&test1,&test2);

    test1.a = 1;
    test1.b = 2;
    test1.c = 3;

    for ( i=0; i<12; i++ ) { 
        test2.str[i] = i;
    }

    // 3. test2에 test1 넣어보기

    pointing_test_3(&test2, &test1);


    test1.a = 1;
    test1.b = 2;
    test1.c = 3;

    for ( i=0; i<12; i++ ) { 
        test2.str[i] = i;
    }



    // 4. test3에 test1, test2 넣어보기
    pointing_test_4( test3, (void *)&test1, 0 );
    {
        int_str_t   *tmp;
        tmp = (int_str_t *)test3;

        printf(" a [%x]\n", tmp->a);
        printf(" b [%x]\n", tmp->b);
        printf(" c [%x]\n", tmp->c);



    }
    ptr= test3;
    ptr += sizeof(int_str_t);

    // test4 초기화 
    test4.a=1;
    test4.b=2;
    test4.c=3;
    test4.d=4;
    test4.str[0]= '1';
    test4.str[1]= '2';
    test4.str[2]= '3';
    test4.str[3]= 0;

    pointing_test_4( &test3[sizeof(int_str_t)], (void *)&test2, 1 );
    {
        char_str_t *tmp;
        tmp = (char_str_t *) ptr;

        for( i = 0; i < sizeof(test2) ; i++){
            printf("test3[%d]: [%x]\n",i, tmp->str[i]);
        }

    }


    ptr += sizeof(int_str_t);
    pointing_test_4( ptr, ( void *)&test4, 2 );
    {
        test_str_t *temp;
        temp = (test_str_t *) ptr;

        printf("a [%x]\n", temp->a);
        printf("b [%x]\n", temp->b);
        printf("c [%x]\n", temp->c);
        printf("d [%x]\n", temp->d);
        printf("str [%s]\n", temp->str);

    }

    for ( i=0; i<sizeof(int_str_t)+sizeof(char_str_t)+sizeof(char_str_t); i++ ) { 
        printf("---->test3[%d]: [%x]\n",i, test3[i]);
    }
}


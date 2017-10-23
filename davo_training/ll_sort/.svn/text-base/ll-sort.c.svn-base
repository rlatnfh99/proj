#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> 

#ifndef NULL
#define NULL ((void*)0)
#endif

typedef struct r_node {
	int     		value;
	struct r_node 	*next;
} cpu_f_node;

cpu_f_node *top=NULL;
int g_malloc=0;
int g_free=0;


int insert( int val )
{
    //ptr cur 초기화
    cpu_f_node *ptr = NULL;
    cpu_f_node *cur = NULL;
    cpu_f_node *prev = NULL;
    int			i=0;

    ptr = malloc(sizeof(cpu_f_node));
    g_malloc++;

    if ( ptr == NULL ) {
        return -1;
    }
    ptr->value = val;

    printf("insert %d\n",val);

    if ( top==NULL ) {
        top = ptr;
        top->next = NULL;
    } 
    if ( top->value > ptr->value ){
        prev = top;
        top = ptr;
        ptr->next = prev;
    }else{
        cur = top; 

        while(1){

            prev = cur;
            cur = cur->next;

            if(cur == NULL){
                cur = ptr;
                prev->next = cur;
                cur->next = NULL;
                break ;
            }else if( ptr->value < cur->value ){
                prev->next = ptr;
                ptr->next = cur;
                break ;
            }
        }
        return 1;
    }
    return -2;
}
int delete( int val )
{
	cpu_f_node *ptr = NULL;
	cpu_f_node *next = NULL;
	cpu_f_node *prev= NULL;

    printf("delete %d\n",val);
    if ( top == NULL ) {
        return -1;
    }


    if ( top && top->value == val ) {
        if ( top->next ) {
            ptr = top;
            top = top->next;
            free(ptr);
            g_free++;
        } else {
            free(top);
            g_free++;
            top = NULL;
        }
        return 1;
    }

    if ( top->next ) {
        prev    = top;
        ptr     = top->next;
    } else {
        return -2;
    }


    while(1){
        if ( ptr->value==val ) {
            if ( ptr->next ) {
                prev->next = ptr->next;
                free(ptr);
                g_free++;
            } else {
                prev->next = NULL;
                free(ptr);
                g_free++;
            }
            return 1;
        } else {
            if ( ptr->next == NULL ) {
                return -3;
            }
            prev = ptr;
            ptr = ptr->next;
        }
#if 0        
        // 첫번째 주소를 삭제할때
        if(ptr->next == NULL && ptr->value == val){
            free(ptr);
            ptr=NULL;
            top=NULL;
            break;
        }else if(ptr->next ==NULL){
            return -1;
        }else if(ptr->next != NULL && ptr->value == val){
            next=ptr->next;
            free(ptr);
            top=next;
            break ;
        }else
// 첫번째 이외의 주소에 있는 데이터 삭제
       if((ptr->next)->value == val){
            prev = ptr;
            ptr=ptr->next;
        }else if(ptr->value == val){
            next=ptr->next;
            prev->next=next;
            free(ptr);
            ptr=NULL;
            break; 
        }
#endif        
    }
	return 1;
}

void print_ll( void )
{
    cpu_f_node *ptr = NULL;

    ptr = top;

    printf("------------------\n");
	while(1) {
		if ( ptr==NULL ) {
		    break;
		} else {
            printf("value %d\n", ptr->value);
            ptr = ptr->next;
		} 

	}
    printf("\n");
    getchar(); 
}

void freeall( void )
{
	cpu_f_node *ptr = NULL;
	cpu_f_node *next = NULL;
	

	ptr = top;
	while(1) {
		if ( ptr==NULL ) {
			break;
		} else {
			next = ptr->next;
			free(ptr);
            g_free++;
            ptr = next;
		} 

	}
	top = NULL;	
}
int main( int argc, char *argv[] )
{
    delete(10);
    print_ll();
	insert(10);
    print_ll();
    printf("\n");
    delete(10);
    print_ll();
    printf("\n");
	insert(1);
    print_ll();
    printf("\n");
   insert(2);
    print_ll();
    printf("\n");
	 insert(1);
    print_ll();
    printf("\n");
    insert(8);
    print_ll();
    printf("\n");
	insert(7);
    print_ll();
    printf("\n");
    delete(8);
    print_ll();
    printf("\n");
	insert(4);
    print_ll();
    printf("\n");
	insert(5);
    print_ll();
    printf("\n");
	insert(6);

    print_ll();

    freeall();

    printf("g_malloc %d, g_free %d\n",g_malloc,g_free);
	return 1;
}







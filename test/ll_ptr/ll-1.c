#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h> 

#ifndef NULL
#define NULL ((void*)0)
#endif

typedef struct r_node {
	int     		value;
	struct r_node 	*prev;
	struct r_node 	*next;
} cpu_f_node;

cpu_f_node *top=NULL;

int insert( int val )
{
	//ptr cur 초기화
	cpu_f_node *ptr = NULL;
	cpu_f_node *cur = NULL;
	int			i=0;

	ptr = malloc(sizeof(cpu_f_node));
	
    if ( ptr == NULL ) {
		return -1;
	}
	ptr->value = val;

	if ( top==NULL ) {
		top = ptr;
		top->next = NULL;
	} else {
		cur = top;
		while(1) {
			if ( cur->next==NULL ) {
				cur->next = ptr;
				ptr->next = NULL;
				break;
			} else {
				cur = cur->next;
			}
		}
	}
	return 1;
}

int delete( int val )
{
	cpu_f_node *ptr = NULL;
	cpu_f_node *next = NULL;
	cpu_f_node *prev= NULL;
  
    if ( top == NULL ) {
        return -1;
    }

    if ( top && top->value == val ) {
        if ( top->next ) {
            ptr = top;
            top = top->next;
            free(ptr);
        } else {
            free(top);
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
            } else {
                prev->next = NULL;
                free(ptr);
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

	while(1) {
		if ( ptr==NULL ) {
		    break;
		} else {
	printf("value %d\n", ptr->value);
			ptr = ptr->next;
		} 

	}
    
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
			ptr = next;
		} 

	}
	top = NULL;	
}
int main( int argc, char *argv[] )
{
	insert(1);
	insert(10);

    print_ll();

printf("\n");
	insert(1);
	insert(2);
	insert(3);
	insert(1);
    delete(1);
	insert(4);
	insert(5);
	insert(6);

    print_ll();

    freeall();
	return 1;
}







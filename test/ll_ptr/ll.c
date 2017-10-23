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

int insert( int val )
{
	//ptr cur 초기화
	cpu_f_node *ptr = NULL;
	cpu_f_node *cur = NULL;
	int			i=0;


	ptr = malloc(sizeof(cpu_f_node));
	//	printf("malptr->value:%d\n",ptr->value);
	//printf("malptr->next:%p\n",ptr->next);
	//printf("\n");
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
	//printf("top->value:%d\n",top->value);
	//	printf("top->next:%p\n",top->next);
	//	printf("\n");

	//	printf("ptr->value:%d\n",ptr->value);
	//	printf("ptr->next:%p\n",ptr->next);
	if (cur==NULL){
		return 1;
	}
	//	printf("cur->value:%d\n",cur->value);
	//	printf("cur->next:%p\n",cur->next);

	//	printf("\n");

	return 1;
}
/*
int delete( int val )
{
	cpu_f_node *ptr = NULL;

	cpu_f_node *next = NULL;
	ptr = top;

	while(1){

		printf("value %d\n",ptr->value);
		ptr = ptr->next;
		if(ptr->value == val){		
			next=ptr->next;
			free(ptr);
			ptr=NULL;
			ptr = next;
		}
	}
	return 1;
}
*/
void print_ll( void )
{
	cpu_f_node *ptr = NULL;

	ptr = top;
	while(1) {
		if ( ptr==NULL ) {
	printf("%s:%d \n",__FUNCTION__, __LINE__);
			break;
		} else {
	printf("%s:%d \n",__FUNCTION__, __LINE__);
	printf("value %d\n",ptr->value);
			ptr = ptr->next;
            printf("ptr_ad -> %p\n",ptr);
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
/*			
			free(ptr);
			ptr = ptr->next; 
*/
		} 

	}
	top = NULL;	
}
int main( int argc, char *argv[] )
{
	insert(1);
	insert(2);
	insert(3);
	insert(4);
	insert(5);
	insert(6);


	print_ll();

	//delete(4);

	print_ll();

	freeall();

	return 1;
}







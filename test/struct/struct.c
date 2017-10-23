#include <stdio.h>
#include <sys/stat.h> 

#ifndef NULL
#define NULL ((void*)0)
#endif

////////////////////////////////////////////////
///////////// CPU FIFO ////////////////////////
////////////////////////////////////////////////


typedef struct r_node {
	int     cpuused;
	struct r_node *next;
} cpu_f_node;



int main( int argc, char *argv[] )
{
	cpu_f_node *ptr=NULL;
	cpu_f_node *ptr0=NULL;
	cpu_f_node *ptr1=NULL;
	cpu_f_node *ptr2=NULL;

	ptr0 = malloc(sizeof(cpu_f_node));
	ptr1 = malloc(sizeof(cpu_f_node));
	ptr2 = malloc(sizeof(cpu_f_node));

	ptr0->next = ptr1;
	ptr1->next = ptr2;
	ptr2->next = NULL;

	ptr = ptr0;
	while(1) {
		if (ptr==NULL) {
			break;
		}

		printf("ptr %p\n",ptr);
		ptr = ptr->next;
	}

	return 1;
}







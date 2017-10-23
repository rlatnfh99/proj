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
	struct r_node *prev;
	struct r_node *next;
} cpu_f_node;

#define MAX_CPU_BUFNUM 12
static cpu_f_node   g_hBuf[MAX_CPU_BUFNUM];

static cpu_f_node   *bottom;
static cpu_f_node   *top;

static int is_init = -1; 

void init_cpu_fifo( void  )
{
	int i=0;

	bottom = NULL;
	top = NULL;
	is_init = 1;

	for(i=0;i<MAX_CPU_BUFNUM;i++) {
		printf("g_hBuf %02d -> %p\n",i,&g_hBuf[i]);
	}
}

cpu_f_node *alloc_cpubuf( void )
{
	int i;
	for(i=0; i<MAX_CPU_BUFNUM; i++) {
		if ( g_hBuf[i].cpuused == 0 ) { 
			return &g_hBuf[i];
		}   
	}   
	return NULL;
}

void free_cpubuf( cpu_f_node *ptr )
{
	ptr->cpuused = 0;
}

// push.
int push_cpu_f( int cpu_f )
{
	cpu_f_node   *tmp;

	if ( is_init < 0 ) { 
		init_cpu_fifo();
	}   


	if( bottom == NULL ) {
		tmp = (cpu_f_node *)alloc_cpubuf();
		if ( tmp == NULL ) {
			return 0;
		}

		tmp->cpuused = cpu_f;
		tmp->prev = NULL;
		tmp->next = NULL;

		bottom = tmp;
		top = tmp;
	} else {
		tmp = (cpu_f_node *)alloc_cpubuf();
		if ( tmp == NULL ) {
			return 0;
		}

		tmp->cpuused = cpu_f;
		tmp->prev = top;
		tmp->next = NULL;
		top->next = tmp;
		top = tmp;
	}
	
	printf("\n");
	printf("push top(%p) top->next(%p) top->prev(%p)\n",top,top->next,top->prev);
	printf("push bot(%p) bot->next(%p) bot->prev(%p)\n",bottom,bottom->next,bottom->prev);
	return 1;
}

int pop_cpu_f( int *cpu_f )
{
	cpu_f_node   *tmp;
	int cpuused;

	if ( is_init < 0 ) {
		init_cpu_fifo();
	}

	if( bottom == NULL ) {
		return 0;
	} else if( top == bottom ) {
		tmp = top;

		*cpu_f = tmp->cpuused;
		cpuused = tmp->cpuused;

		free_cpubuf( tmp );

		tmp = NULL;
		top = NULL;
		bottom = NULL;
	} else {
		/*  
		// FILO : ygjeon
		tmp = top;
		top = top->prev;
		top->next = NULL;

		 *cpu_f = tmp->cpuused;
		 cpuused = tmp->cpuused;

		 free_cpubuf( tmp );
		 tmp = NULL;
		 */
		// FIFO : ygjeon
		tmp = bottom;
		bottom = bottom->next;
		bottom->prev = NULL;

		*cpu_f = tmp->cpuused;
		cpuused = tmp->cpuused;

		tmp->cpuused = 0;

		free_cpubuf( tmp );
		tmp = NULL;
	}
	return cpuused;
}


// clear
void clear_cpu_f_stack( void )
{
	int val;

	do {
		val=0;
		if ( pop_cpu_f( &val ) == 0 ) break;
	} while( 1 );
}

void print_cpu_f( void )
{
	cpu_f_node   *tmp;

	if ( is_init < 0 ) {
		init_cpu_fifo();
	}

	tmp     = bottom;
	do {
		if( bottom == NULL ) {
			return ;
		} else if( top == bottom ) {
			printf("%p    %d\n",top,top->cpuused);
			return ;
		} else {
			printf("%p    %d\n",tmp,tmp->cpuused);
			if ( tmp->next != NULL ) tmp = tmp->next;
			else return ;
		}
	} while( 1 );
}

// fifo : 
int main( int argc, char *argv[] )
{
	int i;
	int val;

	for(i=0;i<=MAX_CPU_BUFNUM;i++) {
		push_cpu_f(i+1);
	}

	pop_cpu_f(&val);
	push_cpu_f(72);
	print_cpu_f();

}







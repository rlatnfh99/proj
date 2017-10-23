#include <stdio.h>

#define 	MAX_ARRAY	15
typedef struct {
	int		value;
	int 	next;
	int		prev;
}FIFO_T;

FIFO_T	g_fifo[MAX_ARRAY];

int		bottom=0;
int		top=0;

void init_array( void )
{
	int i=0;

	for(i=0;i<MAX_ARRAY;i++) {
		g_fifo[i].value 	= -1;
	}
	bottom = 0;
	top = 0;
}

int push( int val )
{
	if ( bottom == 0 && top == 0 ) {
		g_fifo[bottom].value = val;
		printf("push -> %d\n",val);
		bottom = 1;
		top = 0;
	} else {
		g_fifo[bottom].value = val;
		printf("push -> %d\n",val);
		bottom = bottom + 1;
	}

	return 1;
}

int pop( int *val )
{
	*val = g_fifo[top].value;
	printf("pop  -> %d\n",*val);
	top = top + 1;
	return 1;
}

void display( void )
{
	int 	i=0;
	for(i=top;i<bottom;i++) {
		printf("display   %d\n",g_fifo[i].value);
	}
}

int main( void )
{
	int 	val=0;

	init_array();

	push(1);
	push(2);
	push(3);
	push(4);

	display();

	pop( &val );

	display();

	push(1);

	display();
	return 1;
}

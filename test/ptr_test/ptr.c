#include <stdio.h>

#define MAX_MEM  1024

typedef struct {
	char		name[512];
	int			telnum;
	int			seq;
}my_t;


int func_sum( char *array )
{
	int i=0;
	int sum=0;

	printf(" called  %p\n",array);
	for(i=0;i<MAX_MEM;i++) {
		sum = array[i] + sum;
	}
	return sum;
}

// 1024 = 1Kbyte
int main( void )
{
	int i=0;
	int sum=0;
	char array[MAX_MEM];

	printf(" calling  %p\n",array);
	for(i=0;i<MAX_MEM;i++) {
		array[i] = 1;
	}
	sum = func_sum(array);

	printf("sum is %d\n",sum);

	return 1;
}

#include <stdio.h>

char *ptr = NULL;

int main( int argc, char *argv[] )
{
	int 	num=0;

	if ( argc<2 ) {
		printf("usage : ptr num#\n");
		return 0;
	}

	num = atoi(argv[1]);

	printf("ptr => %p\n",ptr);
	ptr = malloc(num);
	printf("ptr => %p\n",ptr);

	free(ptr);
	ptr = NULL;
	printf("ptr => %p\n",ptr);
	return 1;
}

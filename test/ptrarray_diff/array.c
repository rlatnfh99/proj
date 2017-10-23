#include <stdio.h>

char ptr[1024];

int main( int argc, char *argv[] )
{
	int 	num=0;

	if ( argc<2 ) {
		printf("usage : ptr num#\n");
		return 0;
	}

	printf("ptr => %p\n",ptr);
	return 1;
}

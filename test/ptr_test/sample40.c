#include <stdio.h>

int main(int arcg, char* argv[])
{
	int a;
	int *b;

	a = 123;

	b = &a;
	
	printf("변수 a의 어드레스 : %d\n",b);

	printf("변수 a의 값 : %d\n", *b);

	return 0;
}

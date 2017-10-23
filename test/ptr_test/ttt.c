#include <stdio.h>

int main ( void )
{
	char a[80];

	strcpy(a, "davolink");

	printf("%s\n", a);
	printf("%c\n", a[3]);
	printf("%d\n", &a[3]);

	return 0;

}

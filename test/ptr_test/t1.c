#include <stdio.h>

typedef struct {
	char		name[512];
	int			telnum;
	int			seq;
}my_t;

void print_info_value( my_t info )
{
	printf("name    : [%s]\n",info.name);
	printf("telnum  : [%d]\n",info.telnum);
	printf("seq     : [%d]\n",info.seq);
}

// 1024 = 1Kbyte
int main( void )
{
	my_t info;

	printf(" my_t size is %d\n",sizeof(my_t));

	strcpy(info.name,"kimsuro");
	info.telnum 	= 100;
	info.seq 		= 200;

	print_info_value( info );
	print_info_ptr();

	return 1;
}




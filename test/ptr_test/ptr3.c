#include <stdio.h>

typedef struct {
	char		name[1024];
	int			telnum;
	int			seq;
}my_t;

int add_one_value( my_t info )
{
	info.seq = info.seq + 1;
	return info.seq;
}

void add_one_ptr( my_t *info ) 
{
	info->seq = info->seq + 1;
	return;
}


// 1024 = 1Kbyte
int main( void )
{
	my_t 	info;
	int 	i;
	int 	val;

	info.seq 		= 1;
	for(i=0;i<1000000;i++) {
		//info.seq = add_one_value(info);
		add_one_ptr(&info);
	}
	printf("%d\n",info.seq);

	return 1;
}




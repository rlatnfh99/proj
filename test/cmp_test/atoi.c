#include <stdio.h>
#include <string.h>

#define NUM_TEN	10
int suro_mult( int num )
{

	int ten=1;
	for((num-2); num>0; num--){

		ten=ten*NUM_TEN;
	//	printf("H3num:%d\n\n",num);
	//	printf("H3ret:%d\n\n",ret);
	}
return ten;

//		printf("H4ret:%d\n\n",ret);
}

int suro_atoi( char *str )
{
	int i,j;
	int sum = 0;
	int	multi = 0;
	int dec;
	int ten  = 0;
	int	len;

	if ( str == NULL ) {
		printf("str is NULL \n");
		return -1;
	}

	len = strlen(str);
	
	for(i=0,j=(len-1); i<len, j>=0; i++,j--){
//printf("j:%d\n",j);
	ten  = suro_mult(j);

		dec = str[i]-48;
//		printf("str[%d] = [%c], dsc[%d] \n",i ,str[i], dec);
		if ( dec < 0 || dec >= 10 ) {
//			printf("out of range - idx(%d), val(%d)\n",i ,dec);
			break;
		}
	//	if(ten == 0){
	//		ten = 1;
//		}
		multi = dec*ten;
//printf("multi:%d\n",multi);
//printf("sum:%d\n",sum);
		sum = sum + multi;
//printf("sum:%d\n",sum);
	}	

	return sum;	
}

int main (void)
{
	char *str="12345";
	int number=0;

	number = suro_atoi(str);
	printf("strnum(%s) --> number(%d)\n",str, number);

}



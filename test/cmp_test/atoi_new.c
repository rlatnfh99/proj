#include <stdio.h>
#include <string.h>

#define NUM_TEN	10
int ten_mult( int num )
{
	int ten=1;

	for(; num>0; num--){

		ten=ten*NUM_TEN;
	}
	return ten;

}

int suro_atoi( char *str )
{
	int i,j;
	int sum = 0;
	int	multi;
	int dec;
	int ten;
	int	len;

	if ( str == NULL ) {
		printf("str is NULL \n");
		return -1;
	}

	len = strlen(str);
	// .......

	for(i=0,j=(len-1); i<len, j>=0; i++,j--){
	
		ten  = ten_mult(j);

		dec = str[i]-48;
//		if(	dec == -3 ){
		if (str[i]==45){
			continue;
		}
		else	if ( dec<0  || dec >= 10 ) {

	//if ( dec<-3 || -3 <dec <0  || dec >= 10 ) {
//			break;
//		}else if (str[i]==45){
//			continue;
		}
		multi = dec*ten;
		sum = sum + multi;
		if(sum>2147483647){
			sum=214743647;
		}
	}

	if(str[0]==45){
		sum=-sum;
	}
	return sum;	
}

int main (int argc, char *argv[])
{
	char *str="00045123";
	int number;

	if ( argc < 2 ) { 
		return 0;
	}

	number = atoi(argv[1]);
	printf("strnum(%s) --> number(%d)\n",str, number);

	number = suro_atoi(argv[1]);
	printf("strnum(%s) --> number(%d)\n",str, number);

	return 0;

}



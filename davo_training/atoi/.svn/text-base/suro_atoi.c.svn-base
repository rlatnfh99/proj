#include <stdio.h>
#include <string.h>

#define SURO_MAX_LEN 100
#define NUM_TEN	10
size_t suro_numlen( char *str)
{
	size_t len = 0;
	char strhad = str[0];

	if (str == NULL){
		return 0;
	}

	if (strhad == '-' || strhad == '+'){
		str[0]='0';
		str++;
	}

	while(*str == '0')
	{
		str++;
	}

	while(*str){
		if( *str >= '0' && *str <= '9'){
		}else{
			break;
		}
		len++;
		if(len>=SURO_MAX_LEN){
			break;
		}
		str++;
	}
	return len;
}
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
	int i,j,l;
	int sum = 0;
	int	multi;
	int dec;
	int ten;
	int	len;
	char *P_lim_num = "2147483647";
	char *M_lim_num = "-2147483648";
	char strhad; 

	if ( str == NULL ) {
		return -1;
	}

	strhad = str[0];

	len = suro_numlen(str);
		
	
	if( len == 11 && strhad== '-'){
		for ( i=0; i<len; i++ ) {
			if( str[i] > M_lim_num[i] ){
				return -2147483648;
			}
		}
	}else if( len==10 && strhad != 45 ){
		for ( i = 0; i < len; i++ ){
			if( str[i] > P_lim_num[i] ){
				return 2147483647;
			}
		}
	}else if(len >10 && strhad ==45){
		return -2147483648;
	}else if(len >10 && strhad !=45){
		return 2147483647;
	}

	while( *str == '0'){
		str++;
	}

	for(i=0,j=(len-1); i<len, j>=0; i++,j--){
		ten  = ten_mult(j);

		dec = str[i]-48;
		if (i>0 && str[i]=='-'){
			break;
		}else if (str[i]=='-'){
			continue;
		}else if ( dec<0  || dec >= 10 ){
			break;
		}

		multi = dec*ten;
		sum = sum + multi;
	}
	
	if(strhad==45){
		sum=-sum;
	}
	return sum;	
}

int main (int argc, char *argv[])
{
	char *str="00045123";
	int number;

	number = atoi(argv[1]);
	printf("strnum(%s) --> number(%d)\n",str, number);

	number = suro_atoi(argv[1]);
	printf("strnum(%s) --> number(%d)\n",str, number);

	return 0;

}



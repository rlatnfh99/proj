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
	if (strhad == '-'){
		str[0]='0';
		str++;
		len++;
	}

	while(*str == '0')
	{
		printf("*str:%d\n",*str);
		str++;
	}
	while(*str){
		if( *str >= '0' && *str <= '9'){
			printf("E str[0]:%d\n",str[0]);
		}else{
			break;
		}
		len++;
		if(len>=SURO_MAX_LEN){
			break;
		}
		str++;
	}
	printf("%d\n",len);
	return len;
}
int ten_mult( int num )
{
	int ten=1;

	for(; num>0; num--){

		ten=ten*NUM_TEN;
		printf("ten : %d\n",ten);
	}
	return ten;

}

int suro_atoi( char *str )
{
	int i,j,k,l;
	int sum = 0;
	int	multi;
	int dec;
	int ten;
	int	len;
	char *P_lim_num = "2147483647";
	char *M_lim_num = "-2147483648";
	char strhad = str[0];
	if ( str == NULL ) {
		return -1;
	}

	printf("%s():%d str(%p)\n", __FUNCTION__, __LINE__, str);
	len = suro_numlen(str);
	printf("%s():%d str(%p)\n", __FUNCTION__, __LINE__, str);
	
		
	
	if( len == 11 && strhad== 45){
		for ( k=0; k<len; k++ )
		{
			if( str[k] > M_lim_num[k] ){
				return -2147483648;
			}

		}
	}else if( len==10 && strhad != 45 ){
		for ( l = 0; l < len; l++ ){
			if( str[l] > P_lim_num[l] ){
				return 2147483647;
			}
		}
	}else if(len >10 && strhad ==45){
				return -2147483648;
	}else if(len >10 && strhad !=45){

				return 2147483647;
		
	}

	printf("*str[%d]\n", *str);
	while( *str == '0'){
	printf("*str[%d]\n", *str);
	printf("%s():%d\n", __FUNCTION__, __LINE__);
		str++;
	}

	for(i=0,j=(len-1); i<len, j>=0; i++,j--){
	
		ten  = ten_mult(j);

		printf("103 str[%d]:%d\n",i,str[i]);


		dec = str[i]-48;
		if (i>0 && str[i]=='-'){
			break;
		}else if (str[i]=='-'){
			continue;
		}else if ( dec<0  || dec >= 10 ){
			break;
		}

	printf("dec[%d]: %d\n",i, dec);
		multi = dec*ten;
		sum = sum + multi;
		printf("%d\n",sum);
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

	if ( argc < 2 ) { 
		return 0;
	}

	number = atoi(argv[1]);
	printf("strnum(%s) --> number(%d)\n",str, number);

	number = suro_atoi(argv[1]);
	printf("strnum(%s) --> number(%d)\n",str, number);

	return 0;

}



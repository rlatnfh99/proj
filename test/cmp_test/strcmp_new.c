#include <stdio.h>


int suro_strcmp( char *dst, char *src)
{
	int  i=0;
	int ret;
	if (dst == NULL || src==NULL){
		return ;
	}

	while(*src&& *dst) {	
		printf("%c %c\n",dst[i],src[i]);
		if(*src>= '0' && *src <= '9'){
		}else if(*src >= 'a' && *src <='z'){
		}else if(*src >='A' && *src <= 'Z'){
		}else if(*src >=' '){
		}else{
			return -1;
		}

		if(*dst>= '0' && *dst <= '9'){
		}else if(*dst >= 'a' && *dst <='z'){
		}else if(*dst >='A' && *dst <= 'Z'){
		}else if(*dst >=' '){
		}else{
			return -1;
		}
		
		if(*dst != *src){
			ret = -1;
			break;
		}else{
			ret = 0;
		}
		
		src++;
		dst++;
	}

	return ret;
}


int main ( void )
{
	char dst[512]="compare";
	char src[512]="compare";
	char test[512]="computer";
	int cmp= 0;
	
	cmp = suro_strcmp(dst,src);
	printf("[%d]\n",cmp);
	
	cmp = suro_strcmp(dst,test);
	printf("[%d]\n",cmp);

	//cmp = suro_strncmp(dst,test,333);
	//printf("[%d]\n",cmp);
}

#include <stdio.h>

int suro_strncmp( char *dst, char *src,int num)
{
	int  i=0;
	int ret;
	if (dst == NULL || src==NULL){
		return -1;
	}
	if (num <= 0 ){
		return -1;
	}
	for (i=0;i<num;i++) {
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
		
		if(dst[i] != src[i]){
			ret = -1;
			break;
		}else{
			ret = 0;
		}

	}

	return ret;
}


int main ( void )
{
	char dst[512]="compare";
	char src[512]="computer";
	int cmp= 0;
	
	cmp = suro_strncmp(dst,src,4);
	printf("[%d]\n",cmp);
	
	cmp = suro_strncmp(dst,src,5);
	printf("[%d]\n",cmp);

}

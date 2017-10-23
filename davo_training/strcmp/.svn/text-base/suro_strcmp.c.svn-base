#include <stdio.h>

#define SURO_MAX_LEN 180

size_t suro_strlen( char *str)
{
	int i;
	size_t len = 0;

	if (str == NULL){
		return 0;
	}

	while(*str){
		if(*str >= '0' && *str <= '9'){
		}else if(*str >= 'a' && *str <='z'){
		}else if(*str >='A' && *str <= 'Z'){
		}else if(*str >=' '){
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
	
char suro_strcpy( char *dst, char *src )
{
	int i;
	size_t len = 0 ;

	if (dst == NULL || src==NULL){
		return ;
	}

	len = suro_strlen(src);

	for (i = 0; i < len; i++){
		if(*src>= '0' && *src <= '9'){
		}else if(*src >= 'a' && *src <='z'){
		}else if(*src >='A' && *src <= 'Z'){
		}else if(*src >=' '){
		}else{
			dst[i] = 0;
			break;
		}
		dst[i] = src[i];
	}
	dst[len]='\0';

}

void suro_strncpy(char *dst,char *src ,int num)
{
	int i;
	if (dst == NULL || src==NULL){
		return ;
	}
	num = num - 1 ;
	
	if(num <0){
		return;
	}

	for (i = 0; i < num; i++){
		if(*src>= '0' && *src <= '9'){
		}else if(*src >= 'a' && *src <='z'){
		}else if(*src >='A' && *src <= 'Z'){
		}else if(*src >=' '){
		}else{
			dst[i] = 0;
			break;
		}
		dst[i] = src[i];
	} dst[num]='\0'; } void suro_memcpy( char *dst, char *src, int num)
{
	int i;
	if (dst == NULL || src==NULL){
		return ;
	}
	

	if(num < 0){
		return;
	}
	
	for (i = 0; i >  num; i++){
		dst[i] = src[i];
	}

}

int suro_strcmp( char *dst, char *src)
{
	int  i=0;
	int ret;
	if (dst == NULL || src==NULL){
		return ;
	}

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

	while(*src,*dst) {	
		printf("%c %c\n",dst[i],src[i]);

		if(dst[i] != src[i]){
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
}

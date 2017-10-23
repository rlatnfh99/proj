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
	}
	dst[num]='\0';

}

void suro_memcpy( char *dst, char *src, int num)
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
int main ( void )
{
	char dst[5];
	char src[180];
	
	src[0] = 'd';
	src[1] = 'a';
	src[2] = 'v';
	src[3] = 'o';
	src[4] = 'l';
	src[5] = 'i';
	src[6] = 'n';
	src[7] = 'k';
	src[8] = '\0';
	size_t len = 0;
	
	len = suro_strlen(src);
	printf("LEN [%d]\n",len);

	suro_strcpy(dst,src);
	printf("dst [%s] src [%s]\n", dst,src);

	suro_strncpy(dst,src,5);
	printf("dst [%s] src [%s]\n", dst,src);
	
	suro_memcpy(dst,src,5);
	printf("dst [%s] src [%s]\n", dst,src);
}

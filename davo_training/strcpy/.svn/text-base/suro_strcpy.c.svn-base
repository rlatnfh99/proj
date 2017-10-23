#include <stdio.h>
#include <string.h>

#define SURO_MAX_LEN 180

size_t suro_strlen ( char * s )
{
	size_t len = 0 ; 

	if ( s== NULL) return 0 ; 

	while (*s)
	{   
		if (*s>='0' && *s<='9'){
		}else if (*s>='a' && *s<='z'){
		}else if (*s>='A' && *s<='Z'){
		}else if (*s>=' '){
		}else 
		{   
			break;
		}   
		len++;
		if(len>=SURO_MAX_LEN) break;

		s++;
	}   
	return len;
}



void suro_strcpy( char *dst, char *src )
{
	int i;

	size_t len = 0;

	if (dst== NULL || src== NULL ) {
		return;
	}

	len = suro_strlen(src);


	for ( i = 0; i < len ; i++)
	{
		
		if (src[i]>='0' && src[i]<='9'){
		}else if (src[i]>='a' && src[i]<='z'){
		}else if (src[i]>='A' && src[i]<='Z'){
		}else if (src[i]>=' '){
		}else 
		{   
			dst[i] = 0;
			break;
		}   
	
		dst[i] = src[i];
	}

	dst[len] = '\0';
}


int main ( void )
{
	char dest[5];
	//char *src = "davolink";
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



	printf("[%p] [%p]\n",dest, src);

	suro_strcpy(NULL,NULL);
	suro_strcpy(dest,src);
	printf("dest [%s]\n", dest);
	printf("src [%s]\n", src);
	
	return 1;
}

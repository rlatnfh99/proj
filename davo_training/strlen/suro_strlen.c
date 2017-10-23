#include <stdio.h>

#define SURO_MAX_LEN 100

size_t suro_strlen ( char *s )
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
int main ( void )
{
	size_t len = 0 ;
	
	len = suro_strlen ("davolink");

	printf("[%d]\n",len);
	
	return 1 ;
}

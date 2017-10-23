#include <stdio.h>
#include <string.h>

#define SURO_MAX_LEN 100

// input string : '0'~'9', 'a'~'z', 'A'~'Z'
// max string len. is 100
size_t suro_strlen(char *s)
{
	size_t len=0;
	//printf("received s %p\n",s);

	if ( s==NULL ) return 0;

	while(*s) {
		// printf("s %p [%c]\n",s,*s);
		if ( *s>='0' && *s<='9' ) {
		} else if ( *s>='a' && *s<='z' ) {
		} else if ( *s>='A' && *s<='Z' ) {
		} else if ( *s>=' ' ) {
		} else {
			break;
		}

		len++;
		if ( len>=SURO_MAX_LEN ) break;
		s++;
	}
		
	return len;
}


// 1024 = 1Kbyte
int main( void )
{
	size_t len = 0;

	len = suro_strlen("davolink");
	printf("%d\n",len);

	return 1;
}




#include <stdio.h>
#include <string.h>


int suro_memcmp( char *dst, char *src,int num)
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
		printf("[%X] [%X]\n", (unsigned char )dst[i], (unsigned char )src[i]);
		//printf("%c %c\n",dst[i],src[i]);
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
	char dst[100];
	char src[100];
	int cmp= 0;
	char ttt[] = {
		0x01, 0x03, 0x04, 0x07, 0x45
	};
	char ttt2[] = {
		0x01, 0x03, 0x04, 0x17, 0x45
	};
	

	memcpy(dst,src,100);
	cmp = suro_memcmp(dst,src,100);
	printf("ret=[%d]\n",cmp);
	
	cmp = suro_memcmp(dst,src,5);
	printf("ret=[%d]\n",cmp);

	cmp = suro_memcmp(ttt, ttt2, 3);
	printf("ret=[%d]\n",cmp);

	cmp = suro_memcmp(ttt, ttt2, 5);
	printf("ret=[%d]\n",cmp);
}

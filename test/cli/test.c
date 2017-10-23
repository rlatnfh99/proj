#include<stdio.h>

int main(void)
{
    mkdir("./pink", 0777);
    chmod("./pink", 0777);
    return 0;
}

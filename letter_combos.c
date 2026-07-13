#include<stdio.h>
#include<stdlib.h>

int main()
{
    char *s = (char *)malloc(4*sizeof(char));
    char **a = (char **)malloc( 200*4*sizeof(char));
    a[0][0] = 'd';
    printf("%c\n", a[0][0]);
}



#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    while(n!=1)
    {
        printf("%d ", n);
        if(n%2)n = 3*n + 1;
        else n = n/2;
    }
    printf("1");
}

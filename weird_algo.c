#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned long long int n;
    scanf("%llu", &n);
    while(n!=1)
    {
        printf("%llu ", n);
        if(n%2)n = 3*n + 1;
        else n = n/2;
    }
    printf("1");
}

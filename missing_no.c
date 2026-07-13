#include<stdio.h>

int main()
{
    unsigned long long int n, x;
   unsigned long long  sum=0;
    scanf("%llu", &n);
    for(int i=0; i<n-1; i++)
    {
        scanf("%llu", &x);
        sum += x;
    }
    printf("%llu", (n)*(n+1)/2 - sum);
}


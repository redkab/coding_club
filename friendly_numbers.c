#include<stdio.h>

int digSum(int x)
{
    int sum=0;
    while(x)
    {
        sum += x%10;
        x /= 10;
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {

    int n, k;
    scanf("%d", &n);
    int count=0;
    for(int i=0; i<=81; i++)
    {
        k = n+i;
        if(digSum(k)==i)count++;
    }
    printf("%d\n", count);
    }
}

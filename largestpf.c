#include<stdio.h>

int is_prime(int x)
{
    int i;
    for(i=2; i*i <= x; i++)
    {
        if(x%i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int x=10;
    int i, max;
    for(i=2; i <= x/2; i++)
    {
        if(x%i == 0 && is_prime(i))
        {
            max = i;
        }
    }
    printf("%d\n", max);
}

#include<stdio.h>

long long remove_zeroes(long long n)
{
    int digit;
    long long rev=0,sum=0, prod=1,temp = n;
    int rem;
    while(temp > 0)
    {
        digit = temp%10;
        if(digit != 0)
        {
            sum = sum*10 + digit;
        }
        temp /= 10;
    }
    while(sum>0)
    {
        rem = sum%10;
        rev = rev*10 + rem;
        sum /= 10;
    }
    return rev;
}

int main()
{
    long long x=1010123;
    printf("%lld", remove_zeroes(x));
}

    




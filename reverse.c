#include<stdio.h>

int reverse(int x)
{
    int rem, sum=0;
    while(x)
    {
        rem = x%10;
        sum = sum*10 + rem;
        x /= 10;
    }
    return sum;
}

int is_palindrome(int x)
{
    if(x<0) return 0;
    else return reverse(x) == x;
}

int main()
{
    printf("%d\n", is_palindrome(-121));
}

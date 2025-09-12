#include<stdio.h>

int is_armstrong(int x)
{
    int digit;
    int sum=0;
    int d_cube;
    int temp;
    temp = x;
    while(x>0)
    {
        digit = x%10;
        d_cube = digit*digit*digit;
        sum += d_cube;
        x /= 10;
    }
    return sum == temp;
}

int main()
{
    int x;
    printf("Enter the number\n");
    scanf("%d", &x);
    if( is_armstrong(x))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
}

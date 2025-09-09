#include<stdio.h>

int reverse_integer(int x)
{
    int rem=0;
    int reverse = 0;
    if (x<0)
    {
        x = 0-x;
    }

    while(x>0)
    {
        rem = x%10;
        reverse = 10*reverse + rem;
        x = x/10;
    }
    if(x>0)
    {
        return reverse;
    }
    if (x <= 0)
    {
        return 0 - reverse;
    }
}

int main()
{
    int x;
    printf("Enter your number\n");
    scanf("%d", &x);
    int a;
    a = reverse_integer(x);
    printf("Reverse is %d\n", a);
}


#include<stdio.h>

int main()
{
    int a, b, i, small;
    a = 36000000;
    b = 7200000;
    int hcf = 1;
    //printf("Enter the numbers\n");
    //scanf("%d %d", &a, &b);
    if(a<b)
    {
        small = a;
    }
    else
    {
        small = b;
    }
    for(i=2; i<=small; i++)
    {
        if(a%i == 0 && b%i == 0)
        {
            hcf = i;
        }
    }
    printf("GCD is %d\n", hcf);
}



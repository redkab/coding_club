#include<stdio.h>

int main()
{
    int a,b,c,i;
    int n=2;
    a=0;
    b=1;
    for(i=2; i<= n; i++)
    {
        c = a+b;
        if(i == n)
        {
            printf("%d", c);
        }
        a=b;
        b=c;
    }
}

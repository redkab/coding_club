#include<stdio.h>

int combos(int n)
{
    if(n%2)return 0;
    int c=0;
    //2x+4y=n;
    for(int x=0; n-2*x>=0; x++)
    {
        if((n-2*x)%4==0)c++;
    }
    return c;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", combos(n));
    }
}

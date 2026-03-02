#include<stdio.h>

int diff(int n)
{
    if(n==2)return 2;
    if(n%2)return 1;
    else return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        printf("%d\n", diff(n));
    }
}

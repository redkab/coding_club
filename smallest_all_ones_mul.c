#include<stdio.h>

int min_mul(int k)
{
    if(k%2==0)return -1;
    int num=0;
    for(int i=1; ; i++)
    {
        num = num*10 + 1;
        if(num%k==0)return i;
    }
    return 0;
}

int main()
{
    printf("%d\n", min_mul(2));
}

#include<stdio.h>
#include<math.h>

int rem(int n, int m)
{
    if(n<10)return (int)pow(2, n)%m;
    return rem(n/2, m)*rem(n - n/2, m)%m;
}


int main()
{
    int m = pow(10, 9)+7;
    printf("%d\n", rem(32, m));
}

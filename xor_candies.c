#include<stdio.h>
#include<string.h>

long long int maxXOR(long long int x)
{
    int c=0;
    while(x)
    {
        c++;
        x/=2;
    }
    long long int ans=1;
    for(int i=0; i<c; i++)
    {
        ans = ans*2;
    }
    return ans-1;
}

int main()
{
    long long int n, k;
    scanf("%lld %lld", &n, &k);
    if(k==1)
    {
        printf("%lld", n);
        return 0;
    }
    printf("%lld", maxXOR(n));

}


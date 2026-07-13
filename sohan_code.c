#include<stdio.h>
#include<math.h>
int op(long long a,long long b);
void check(long long a,long long b);
int main()
{
    long long a=50000000;
    long long b = 4;
    check(a,b);
    
    return 0;
}
void check(long long a,long long b)
{
    if(a==b) printf("2\n");
    else if(a<b) printf("1\n");
    else op(a,b);
}
int op(long long a,long long b)
{
    long long k=0,min=2000000000,current=0;
    if(b==1) k++;
    while(1)
    {
        current = 1+k+log(a)/log(b+k);
        if(min>current)
        {
            min = current;
            k++;
            current=0;
        }
        else break;
    }
    printf("%lld\n",min);
}

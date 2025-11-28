#include<stdio.h>
#include<math.h>

int main()
{
    long long int a=50000000;
    long long int b=4;
    long long int i;
    double ok = log(a);
    long long var;
    for(i=b; i<=a; i++)
    {
        var = i*log(i)*log(i);
        if(var > ok)
        {
            printf("%lld\n", i);
            break;
        }
    }
    int steps;
    int logar = log(a)/log(i);
    steps = i-b+1+logar;
    printf("Steps is %d\n", steps);
}

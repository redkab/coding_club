#include<stdio.h>
#include<math.h>

int mono(int n)
{
    int count=1;
    for(int i=1; i<=n; i++)
    {
        int l = log2(i+1);
        if(pow(2,l) == i+1)count++;
    }
    return count;
}

int main()
{
    printf("%d\n", mono(2));
}

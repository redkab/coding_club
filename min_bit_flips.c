#include<stdio.h>

int min_flips(int start, int goal)
{
    int x = start^goal;
    int count=0;
    while(x)
    {
        if(x%2==1)count++;
        x/=2;
    }
    return count;
}

int main()
{
    printf("%d\n", min_flips(10,7));
}



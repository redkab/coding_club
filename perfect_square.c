#include<stdio.h>

int is_perfsq(int num)
{
    int i;
    for(i=0; i*i <= num; i++)
    {
        if(i*i == num) return 1;
    }
    return 0;
}

int main()
{
    int num = 15;
    printf("%d\n", is_perfsq(num));
}


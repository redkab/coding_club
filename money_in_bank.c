#include<stdio.h>
int money(int n)
{
    int days, weeks, money=0;
    weeks = n/7;
    days = n%7;
    money = weeks*28 + (weeks-1)*weeks/2;
    printf("Money after %d weeks is %d\n", weeks, money);
    int i = weeks;
    int j;
    for(j=1; j<=days; j++)
    {
        money += i+j;
        printf("Money is %d\n", money);
    }
    return money;
}

int main()
{
    printf("%d\n", money(10)); 
}

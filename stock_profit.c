#include<stdio.h>

int main()
{
    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(prices)/sizeof(prices[0]);
    int i,j;
    int profit;
    int max_profit = 0;
    
    for(i=0; i<size-1; i++)
    {
        for(j=i+1; j<size; j++)
        {
            profit = prices[j] - prices[i];
            if(profit > max_profit)
            {
                max_profit = profit;
            }
        }
    }

    printf("%d\n", max_profit);
}

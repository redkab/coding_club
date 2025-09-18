#include<stdio.h>

int arr_sum(int arr[], int start, int end)
{
    int sum = 0;
    int i;
    for(i=start; i <= end; i++)
    {
        sum += arr[i];
    }
    return sum;
}
int main()
{
    int i,j;
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int max=0, sum =0;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(i=0; i<size; i++)
    {
        for(j=i; j<size; j++)
        {
            sum = arr_sum(arr, i, j);
            if(sum > max)
            {
                max = sum;
            }
        }
    }
    printf("%d\n", max);
}


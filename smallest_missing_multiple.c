#include<stdio.h>

int arr_search(int arr[], int k, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        if(arr[i] == k)
        {
            return 1;
        }
    }
    return 0;
}
    
int missing_multiple(int nums[], int size, int k)
{
    int i=1, mul;
    while(1)
    {
        mul = k*i;
        if(arr_search(nums, mul, size) == 0)
        {
            return mul;
        }
        i++;
    }
}

int main()
{
    int arr[]= {1,4,7,10,15};
    int k=5;
    printf("%d\n", missing_multiple(arr, 5, k));
}



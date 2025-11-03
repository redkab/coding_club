#include<stdio.h>

int smallest_divisor(int nums[], int numsSize, int threshold)
{
    int sum=0, q, i,div,max=nums[0];
    for(i=0; i<numsSize; i++)
    {
        if(nums[i] > max) max = nums[i];
    }
    for(div=1;div<=max ;div++)
    {
        sum=0;
        for(i=0; i<numsSize; i++)
        {
            if(nums[i] % div == 0)
            {
                q = nums[i]/div;
            }
            else q = nums[i]/div + 1;
            sum += q;
        }
        printf("For div = %d sum is %d\n", div, sum);
        if(sum == threshold) return div;
    }
    return 0;
}

int main()
{
    int arr[]  = {1,2,5,9};
    printf("%d\n", smallest_divisor(arr, 4, 6));
}


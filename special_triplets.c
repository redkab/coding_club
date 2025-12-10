#include<stdio.h>

int special(int *nums, int size)
{
    int count=0;
    int i,j,k;
    for(i=0; i<size; i++)
    {
        for(j=i+1; j<size; j++)
        {
            for(k=j+1; k<size; k++)
            {
                if(nums[i] == nums[j]*2 && nums[k] == 2*nums[j])
                {
                    count++;
                }
            }
        }
    }
    return count;
}

int main()
{
    int arr[] = {8,4,2,8,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", special(arr, size));
}

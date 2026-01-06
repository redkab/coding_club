#include<stdio.h>

int div_count(int x)
{
    int divs=0;
    for(int i=1; i*i<=x; i++)
    {
        if(x%i==0)
        {
            if(i*i==x)divs += 1;
            else divs += 2;
        }
    }
    return divs;
}
int sum(int *nums, int numsSize)
{
    int sum=0;
    for(int i=0; i<numsSize; i++)
    {
        if(div_count(nums[i])==4)
        {
            for(int j=1; j*j<=nums[i]; j++)
            {
                if(nums[i]%j==0)
                {
                    if(j*j == nums[j])sum += j;
                    else sum += j + nums[i]/j;
                }
            }
        }
    }

    
    return sum;
}

int main()
{
    int arr[] = {21, 21};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", sum(arr, size));
}



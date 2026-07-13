#include<stdio.h>
#include<stdlib.h>
void print(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int* plusOne(int* digits, int size, int* returnSize) 
{
    int *ans = (int *)malloc((size+1)*sizeof(int));
    int sum, dig, carry=0, i;
    for(i=size-1; i>=0; i--)
    {
        sum = (carry + digits[i] + (i==size-1));
        dig = sum%10+carry;
        carry = sum/10;
        ans[i+1] = dig;
    }
    ans[i+1] = carry;
    *returnSize = size+1;
    if(ans[0]==0)
    {
        *returnSize = size;
        return &(ans[1]);
    }
    return ans;
}

int main()
{
    int arr[] = {9,9,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int x;
    int *ret = plusOne(arr, size, &x);
    print(ret, size+1);
}


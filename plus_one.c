#include<stdio.h>
#include<stdlib.h>

int *plus(int *digits, int size)
{
    int *ans = (int *)malloc((size+1)*sizeof(int));
    int dig, carry=0, i;
    for(i=size-1; i>=0; i--)
    {
        if(i==size-1)
        {
            dig = (carry +1+ digits[i])%10;
            carry = (carry + 1+digits[i])/10;
        }
        else 
        {
            dig = (carry + digits[i])%10;
            carry = (carry + digits[i])/10;
        }
        ans[i+1] = dig;
    }
    ans[i] = carry;
    return ans;
}
void print(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] = {1,2,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    print(plus(arr, size), size+1);
}

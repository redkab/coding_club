#include<stdio.h>
#include<stdlib.h>

void print(int *arr, int size);
int* plus(int* digits, int size, int* returnSize); 
int* plus(int* digits, int size, int* returnSize) {
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
        print(ans, size+1);
    }
    ans[i+1] = carry;
    *returnSize = size+1;

    if(ans[0]==0)
    {
        printf("return size is %d\n", *returnSize);
        *returnSize--;
        printf("return size is %d\n", *returnSize);
        //*returnSize=size;
        return &(ans[1]);
    }
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
    int arr[] = {9,9,9};
    int x;
    int size = sizeof(arr)/sizeof(arr[0]);
    int *ret = plus(arr, size, &x);
    printf("x is %d\n", x);
    print(ret, x);
}

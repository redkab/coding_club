#include<stdio.h>
int search(int *arr, int len, int ele)
{
    for(int i=0; i<len; i++)
    {
        if(arr[i] == ele) return 1;
    }
    return 0;
}
int distinct_sum(int *arr, int len)
{
    int i, sum=0;
    for(i=0; i<len; i++)
    {
        if(search(arr, i, arr[i])==0)sum += arr[i];
    }
    return sum;
}
void print(int *arr, int len)
{
    for(int i=0; i<len; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\t");
}

int min_len(int *nums, int size,  int k)
{
    int i,j, flag=0,sum, min = size+1;
    for(i=0; i<size; i++)
    {
        for(j=i; j<size; j++)
        {
            sum = distinct_sum(nums+i, j-i+1);
            print(nums+i, j-i+1);
            printf("Sum is %d min length is %d\n", sum, min);
            if(sum>=k && j-i+1<min)
            {
                min = (j-i+1);
                flag++;
            }
        }
    }
    if(flag==0)return -1;
    return min;
}
int main()
{

    int arr[]  ={5,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", min_len(arr, size, 5));
}

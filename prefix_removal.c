#include<stdio.h>

int minLen(int *arr, int n)
{
    int len=0;
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]>=arr[i+1])len = ++i;
    }
    return len;
}

int main()
{
    int arr[] = {1,2,3,4};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", minLen(arr, n));
}

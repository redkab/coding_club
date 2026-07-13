#include<stdio.h>
#include<stdlib.h>

int incCount(long long int *arr, int n)
{
    int c=0;
    for(int i=1; i<n; i++)
    {
        if(arr[i] < arr[i-1])
        {
            c+= arr[i-1] - arr[i];
            arr[i] = arr[i-1];
        }
    }
    return c;
}




int main()
{
    int n;
    scanf("%d", &n);
    long long int *arr = (long long int *)malloc(n*sizeof(long long int));
    for(int i=0; i<n; i++)
    {
        scanf("%lld", arr+i);
    }
    printf("%d", incCount(arr, n));
}


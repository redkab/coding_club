#include<stdio.h>
#include<stdlib.h>
int changes(int *arr, int n)
{
    int count=0;
    for(int i=0; i<n-1; i++)
    {
        if((arr[i] + arr[i+1] == 7)||arr[i] == arr[i+1])count++;
    }
    return count;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int *arr = (int *)malloc(n*sizeof(int));
        for(int i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", changes(arr, n));
        free(arr);
    }
}


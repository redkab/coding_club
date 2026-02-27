#include<stdio.h>
#include<stdlib.h>

int count (int *arr, int n)
{
    int p=0;
    for(int i=1; i<n; i++)
    {
        if(arr[i-1] > arr[i])return 1;
    }
    return 0;
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
        if(count(arr, n))printf("%d\n", 1);
        else printf("%d\n", n);
    }
}

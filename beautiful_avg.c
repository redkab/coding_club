#include<stdio.h>
#include<stdlib.h>

float avg(int *arr, int l, int r)
{
    int sum=0;
    for(int i=l; i<=r; i++)
    {
        sum+=arr[i];
    }
    return sum/(r-l+1);
}


int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n,a;
        scanf("%d", &n);
        int *arr = (int *)malloc(n*sizeof(int));
        for(int i=0; i<n; i++)
        {
            scanf("%d", arr+i);
        }
        int max=-1;
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                a = avg(arr, i, j);
                if(a>max)max = a;
            }
        }
        printf("%d\n", max);
    }
}

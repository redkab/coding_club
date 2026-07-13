#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        printf("ENter n\n");
        int n;
        int *arr = (int *)malloc(n*sizeof(int));
        int k=0;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=0; j<n-1; j++)
            {
                int x;
                scanf("%d", &x);
                sum+=x;
                //printf("sum is %d\n", sum);
            }
            arr[k++] = n*(n+1)/2 - sum;
            printf("Filled %d\n", n*(n+1)/2 - sum);
        }
        for(int i=0; i<n; i++)
        {
            printf("%d ", arr[i]);
        }
        free(arr);
    }
}

        

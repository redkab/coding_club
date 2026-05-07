#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int *arr = (int *)calloc(7, sizeof(int));
        for(int i=0; i<7; i++)
        {
            scanf("%d", arr+i);
        }
        int max=arr[0], sum=0;

        for(int i=0; i<7; i++)
        {
            if(arr[i]>max)max=arr[i];
            sum += arr[i];
        }

        int ans = -sum + 2*max;
        printf("%d\n", ans);
        free(arr);
    }
}


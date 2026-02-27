#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int *arr = (int *)malloc(n*sizeof(int));
        int vals[11] = {0};
        for(int i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
            vals[arr[i]]++;
        }
        int ans;
        for(int i=10; i>=0; i--)
        {
            if(vals[i] >0)
            {
                ans = vals[i];
                break;
            }
        }
        printf("%d\n", ans);
    }
}


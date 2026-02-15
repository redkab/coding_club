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
        for(int i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int o=0, s=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i]==1)o++;
            if(arr[i]==67)s++;
        }
        if(s&&o)printf("Yes\n");
        else printf("No\n");
    }
}


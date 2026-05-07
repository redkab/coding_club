#include<stdio.h>
#include<stdlib.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        int x=0;
        scanf("%d", &n);
        int *arr = (int *)calloc(n, sizeof(int));
        for(int i=0; i<n; i++)
        {
            scanf("%d", arr+i);
            if(arr[i] == 67)x=1;
        }
        if(x)printf("YES\n");
        else printf("NO\n");
    }
}

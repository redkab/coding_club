#include<stdio.h>
#include<stdlib.h>
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n, s, x;
        scanf("%d%d%d", &n, &s, &x);
        int *arr = (int *)malloc(n*sizeof(int));
        int sum=0;
        for(int i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        if(sum > s)printf("NO");
        else if(((sum-s)%x)==0)printf("YES");
        else printf("NO");
        free(arr);
        return 0;
    }
}

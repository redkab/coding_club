#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int power2(int x)
{
    int l = log2(x);
    return x == pow(2, l);
}

int isGood(int *arr, int n)
{
    int b, s,q;
    for(int i=1; i<=n; i++)
    {
        if(arr[i]!=i)
        {
            if(i>=arr[i])
            {
                b=i;
                s=arr[i];
            }
            else
            {
                b = arr[i];
                s = i;
            }
            if(b%s)return 0;
            q = b/s;
            if(!power2(q))return 0;
        }
    }
    return 1;
}
int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int *arr = (int *)malloc((n+1)*sizeof(int));
        arr[0] = 0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d", &arr[i]);
        }
        if(isGood(arr, n))printf("YES\n");
        else printf("NO\n");
        free(arr);
    }
}





#include<stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int x, k;
        scanf("%d %d", &k, &x);
        int ans;
        int p=1;
        for(int i=0; i<k; i++)
        {
            p*=2;
        }
        ans = x*p;
        printf("%d\n", ans);
    }
}

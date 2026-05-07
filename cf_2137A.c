#include<stdio.h>
#include<math.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int x, k;
        scanf("%d %d", &k, &x);
        printf("%d\n", (int)(x * pow(2, k)));
    }
}

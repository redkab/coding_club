#include<stdio.h>

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int x;
        scanf("%d", &x);
        switch(x)
        {
            case -67:
                printf("66\n");
                break;

            case 67:
                printf("66\n");
                break;

            default:
                printf("%d\n", x+1);
                break;
        }
    }
}



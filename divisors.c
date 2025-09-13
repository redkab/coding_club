#include<stdio.h>

int main()
{
    int x;
    int i;
    printf("Enter the number\n");
    scanf("%d", &x);

    for(i=1; i<=x/2; i++)
    {
        if(x%i == 0)
        {
            printf("%d\n", i);
        }
    }
    printf("%d\n", x);
}

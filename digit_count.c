#include<stdio.h>

int main()
{
    int x;
    int i=1;
    int q;
    printf("Enter your number\n");
    scanf("%d", &x);
    q = x/10;
    while(q != 0)
    {
        q = q/10;
        i++;
        //printf("current q is %d\n", q);
    }
    printf("%d has %d digits \n", x, i);
}


#include<stdio.h>

int is_zero(int x)
{
    int q;
    int rem;
    q = x;

    while(q !=0)
    {
        rem = q%10;
        q = q/10;
        if(rem == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int i, b, n;
    printf("Enter the number\n");
    scanf("%d", &n);

    for(i=1; i<n/2; i++)
    {
        b = n-i;
        if( is_zero(i) == 0 && is_zero(b) == 0)
        {
            printf("[%d, %d]\n", i, b);
            //break;
        }
    }
}
        
    


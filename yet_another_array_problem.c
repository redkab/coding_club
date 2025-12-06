#include<stdio.h>
#include<stdlib.h>


int hcf(int a,int b)
{
    int temp,i;
    if(a>b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if(a==b) return a;
    int hcf=1;
    for(i=1; i<=a; i++)
    {
        if(a%i ==0 && b%i==0)
        {
            hcf = i;
        }
    }
    return hcf;
}
int main()
{
    int i,n;
    printf("Enter n\n");
    scanf("%d", &n);
    int *arr = malloc(n*sizeof(int));
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int x,flag=0, minx, gcd, max = arr[0];
    for(i=0; i<n; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    minx=max;
    for(x=2; x<max; x++)
    {
        for(i=0; i<n; i++)
        {
            if((hcf(x,arr[i]) == 1) && x<minx)
            {
                
                
                    minx=x;
                    flag++;
                
            }
        }
    }
    if(flag == 0)
    {
        printf("%d\n", -1);
        return 0;
    }
    printf("%d\n", minx);
}


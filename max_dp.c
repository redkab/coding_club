#include<stdio.h>
#include<limits.h>

int dp(int *a, int *b, int n)
{
    int sum=0;
    for(int i=0; i<n; i++)
    {
        sum += a[i]*b[i];
    }
    return sum;
}

int max_dp(int *a, int *b, int lena, int lenb)
{
    int len, i, j, x, prod, max = INT_MIN;
    if(lena>lenb)x=lenb;
    else x=lena;
    for(len=1; len<=x; len++)
    {
        for(i=0; i<lena-x; i++)
        {
            for(j=0; j<lenb-x; j++)
            {
                prod = dp(a+i, b+j, len);
                printf("Prod is %d\n", prod);
                if(prod>max)max = prod;
            }
        }
    }
    return max;
}

int main()
{
    int a[] = {2,1,-2,5};
    int b[] = {3,0,-6};
    printf("%d\n", max_dp(a, b, 4, 3));
}

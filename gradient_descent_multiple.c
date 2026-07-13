#include<stdio.h>
#include<stdlib.h>

float dp(float *a, float *b, int n)
{
    float sum=0;
    for(int i=0; i <n; i++)
    {
        sum += a[i] * b[i];
    }
    return sum;
}

float f(float *w, float *x, float b, int n)
{
    return dp(w, x, n) + b;
}

float j(float **data, float *w, float b, int n, int m)
{
    float sum=0;
    for(int i=0; i<m; i++)
    {
        sum += (f(w, data[i], b, n) - data[i][n])*(f(w, data[i], b, n)-data[i][n]);
    }
    sum = sum/(float)(2*m);
    return sum;
}

void print(float *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

float diffwj(float **data, int m, int n, int j, float *w, float b)
{
    float sum=0;
    for(int i=0; i<m; i++)
    {
        sum += (f(w, data[i], b, n) - data[i][n])*data[i][j];
    }
    return sum/(float)(m);
}

float diffb(float **data, int m, int n, float *w, float b)
{
    float sum=0;
    for(int i=0; i<m; i++)
    {
        sum += f(w, data[i], b, n) - data[i][n];
    }
    return sum/(float)(m);
}

void copy(float *a, float *b, int n)
{
    for(int i=0; i<n; i++)
    {
        b[i] = a[i];
    }
}

int same(float *a, float *b, int n)
{
    for(int i=0; i<n; i++)
    {
        if(a[i] != b[i])return 0;
    }
    return 1;
}

float *grad_desc(float **data, int m, int n)
{
    float *w = (float *)calloc(n, sizeof(float));
    float b=0;
    float *temp = (float *)malloc(n*sizeof(float));
    while(1)
    {
        printf("Current w is:\n");
        print(w, n);
        for(int i=0; i<n; i++)
        {
            temp[i] = w[i] - diffwj(data, m, n, i, w, b);
        }
        if(same(temp, w, n))break;
        b = b - diffb(data, m, n, w, b);
        copy(temp, w, n);
    }
    return w;
}

int main()
{
    int n,m;
    printf("Enter number of features\n");
    scanf("%d", &n);
    printf("Enter number of examples\n");
    scanf("%d", &m);
    float **data = (float **)malloc(m*sizeof(float *));
    for(int i=0; i<m; i++)
    {
        data[i] = (float *)malloc((n+1)*sizeof(float));
    }
    for(int i=0; i<m; i++)
    {
        printf("Enter %d example\n", i);
        for(int j=0; j<n+1; j++)
        {
            scanf("%f", &data[i][j]);
        }
    }
    float *w = grad_desc(data, m, n);

    print(w, n);


}   

#include<stdio.h>
#include<stdlib.h>
float f(float w, float b, float x)
{
    return w*x + b;
}

float j(int **data, int m, float w, float b)
{
    float sum=0;
    float a;
    for(int i=0; i<m; i++)
    {
        a = f(w, b,data[i][0]) - data[i][1];
        sum += a*a;
    }
    printf("Sum is %f\n", sum);
    float ans;
    ans = ((float)sum)/((float)(2*m));
    return ans;
}

void print(int **data, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++)
        {
            printf("%d ", data[i][j]);
        }
        printf("\n");
    }
}

float diffw(int **data, int m, float w, float b)   //derivative of J wrt w
{
    float sum=0, a;
    for(int i=0; i<m; i++)
    {
        a = f(w, b, data[i][0]) - data[i][1];
        sum += a*data[i][0];
    }
    return sum/((float)(2*m));
}


float diffb(int **data, int m, float w, float b)   //derivative of J wrt b
{
    float sum=0, a;
    for(int i=0; i<m; i++)
    {
        a = f(w, b, data[i][0]) - data[i][1];
        sum += a;
    }
    return sum/((float)(2*m));
}

float *gradient_descent(int **data, int m, float a)
{
    float w=0, b=0, tw, tb;
    while(1)
    {
        tw = w - a*diffw(data, m, w, b);
        tb = b - a*diffb(data, m, w, b);
        if(w==tw && b==tb)break;
        w = tw;
        b = tb;
    }
    float *arr = (float *)malloc(2*sizeof(float));
    arr[0] = w;
    arr[1] = b;
    return arr;
}


int main()
{
    int n=6;
    int **data = (int **)malloc(n*sizeof(int *));
    for(int i=0; i<n; i++)
    {
        data[i] = (int *)malloc(2*sizeof(int));
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<2; j++)
        {
            data[i][j] = i+1;
        }
    }
    print(data, n);
    float *ans = gradient_descent(data, n, 0.001);
    printf("w is %f and b is %f\n", ans[0], ans[1]);
}


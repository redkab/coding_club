#include<stdio.h>

int main()
{
    int x[] = {5, 2, 89, 56, 3, 2};
    int i;
    int max = x[0];
    int size = sizeof(x)/sizeof(x[0]);
    for(i=0; i<size; i++)
    {
        if(x[i] > max)
        {
            max = x[i];
        }
    }
    printf("Largest element is %d\n", max);
}


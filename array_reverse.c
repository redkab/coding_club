#include<stdio.h>

int main()
{
    int x[] = {1, 2, 3, 4, 5, 6};
    int i, temp;
    int size = sizeof(x)/ sizeof(x[0]);
    for(i=0; i<size/2; i++)
    {
        temp = x[i];
        x[i] = x[size - 1 - i];
        x[size - 1 - i] = temp;
    }

    int j;
    for(j=0; j<size; j++)
    {
        printf("%d\t", x[j]);
    }
}


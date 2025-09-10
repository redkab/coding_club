#include<stdio.h>
int array_print(int array[], int size);

int main()
{
    int array[] = {1, 6, 8, 4, 7};
    int i;
    int x=0;
    int size = sizeof(array)/sizeof(array[0]);
    int min_ind, temp;

    for(x=0; x<size-1; x++)
    {
        min_ind = x;
        printf("Value of x is %d\n", x);
        for(i=x+1; i<size; i++)
        {
            if(array[i] < array[min_ind])
            {
                min_ind = i;
            }
        }
        printf("min index = %d and value is %d\n", min_ind, array[min_ind]);

        if(min_ind != x)
        {
            temp = array[x];
            array[x] = array[min_ind];
            array[min_ind] = temp;
            printf("Swapped %d with %d\n", array[x], array[i]);

        }
        printf("Iteration x = %d\n", x);
        array_print(array, size);

    }
}
int array_print(int array[], int size)
{
    int j;
    for(j=0; j<size; j++)
    {
        printf("%d\t", array[j]);
    }
    printf("\n");
}


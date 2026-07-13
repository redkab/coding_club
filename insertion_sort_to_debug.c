#include<stdio.h>
int array_print(int array[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d\t", array[i]);
    }
        printf("\n");
}

int main()
{
    int array_1[] = {1, 4, 3, 6, 7, 5};
    int array_2[]= {0, 0, 0, 0, 0, 0};
    int i, j, ele, a;
    int size = sizeof(array_1)/sizeof(array_1[0]);
    array_2[0] = array_1[0];
    for(i=0; i<size; i++)
    {
        ele = array_1[i];
        for(j=0; j<size; j++)
        {
            if(ele < array_2[j])
            {
                //shift
                for(a = j; a < size - 1; a++)
                {
                   array_2[a+1] = array_2[a];
                } 
                array_2[j] = ele;
            }
            if( ele > array_2[j])
            {
                array_2[j+1] = ele;
            }
        //    array_print(array_2, size);
        }
    printf("i is %d\n", i);
    array_print(array_2, size);
    }
}


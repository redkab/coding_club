#include<stdio.h>
void print_array(int *arr, int size);
void merge(int a[], int sa, int b[], int sb, int c[], int sc)
{
    int i=0;
    int j=0;
    int k=0;
    //printf("Entered merge sort func\n");
    while(1)
    {
        if(a[i] > b[j])
        {
            c[k] = b[j];
            j++;
            k++;
        }
        else
        {
            c[k] = a[i];
            i++;
            k++;
        }
        if(i == sa -1)
        {
            printf("Array a is empty\n");
            break;
        }
        if(j == sb-1)
        {
            printf("Array b is empty\n");
            break;
        }
    }
    int x;
    for(x=i; x<sa; x++)
    {
        c[k] = a[x];
        k++;
    }
    for(x=j; x<sb; x++)
    {
        c[k] = b[x];
        k++;
    }

    //print_array(c, 8);
    //printf("i = %d and j = %d\n", i, j);

}


void print_array(int *arr, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main()
{
    int x[] = {2, 9, 6, 3};
    int y[] = {0, 1, 5, 60};
    int z[100] = {0};
    merge(x, 4, y, 4, z, 100);
    print_array(z, 8);
}


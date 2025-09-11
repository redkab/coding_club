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

int insertion_sort(int arr[], int size)
{
   // int arr[] = {7, 6, 5, 4, 3, 2};
    int i, j, key, a;
    for(i=0; i<size; i++)
    {
        key = arr[i];
        for(j=i-1; j>=0 && key<arr[j]; j--)
        {
            if(key < arr[j])
            {
                arr[j+1] = arr[j];
            }
        }
        arr[j+1] = key;
       // printf("i is %d\n", i);
      //  array_print(arr, size);
    }
    //array_print(arr, size);
 }
#define SIZE 100000
int main()
{
    int large_arr[SIZE];
    int  arr[] = {7, 5, 4, 3, 2, 1};
   // int size = sizeof(arr)/sizeof(arr[0]);
   int size = SIZE;
    int i;
    for(i=0; i<SIZE; i++)
    {
        large_arr[i] = SIZE-i;
    }
    insertion_sort(large_arr, size);
    //array_print(large_arr, size);
}



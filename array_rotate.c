#include<stdio.h>

int array_rotate(int arr[], int size)
{
    int i;
    int temp; 
    temp = arr[size - 1];
    for(i=0; i<size-1; i++)
    {
        arr[i+1] = arr[i];
    }
    arr[0] = temp;
}

int sort_check(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        if(arr[i+1] <= arr[i])
        {
            return 0;
        }
    }
    return 1;
}
            
int main()
{
    int arr[] = {};
    int size = sizeof(arr)/sizeof(arr[0]);
    int i;
    for(i=0; i<size; i++)
    {
        if(sort_check(arr))
        {
            printf("Yes\n");
        }
        if( sort_check(arr) == 0)
        {
            array_rotate(arr);
        }
        
    }
}


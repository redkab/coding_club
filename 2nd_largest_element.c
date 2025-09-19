#include<stdio.h>

int main()
{
    int arr[] = {2, 1, 4, 5 , 3};
    int max=arr[0];
    int i;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(i=0; i<size; i++)
    {
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }
    int max_2 = 0;

    for(i=0; i<size; i++)
    {
        if(arr[i] > max_2 && arr[i] != max)
        {
            max_2 = arr[i];
        }
    }
    printf("%d\n", max_2);
}

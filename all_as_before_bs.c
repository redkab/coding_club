#include<stdio.h>

int a_checker(char arr[], int size)
{
    int i;
    for(i=0; i < size-1; i++)
    {
        if(arr[i+1] < arr[i])
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    char arr[] = "bbbbb";
    int size = sizeof(arr)/sizeof(arr[0]) -1;
    printf("%d\n", a_checker(arr, size));
}


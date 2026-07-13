#include<stdio.h>

int part(int arr[], int size)
{
    int i,j,k,left=0, right=0, difference, count=0;
    for(i=1; i<size; i++)
    {
        for(j=0; j<=i; j++)
        {
            left+=arr[j];
        }
        for(j=i+1; j<size; j++)
        {
            right += arr[j];
        }
        difference = left-right;
        printf("i is %d and diff is %d\n", i,difference);
        if(difference%2==0)count++;
    }
    return count;

    
}


int main()
{
    int arr[] = {1,2,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("%d\n", part(arr, size));
}


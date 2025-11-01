#include<stdio.h>

int missing_multiple(int nums[], int size, int k)
{
    int max=0, q; 
    int i;
    for(i=0; i<size; i++)
    {
        q = nums[i]/k;
        if(q>max) max=q;
    }
    return k*(max+1);
}

int main()
{
    int arr[]= {8,2,3,4,6};
    int k=2;
    printf("%d\n", missing_multiple(arr, 5, k));
}



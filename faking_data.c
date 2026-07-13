#include<stdio.h>
#include<stdlib.h>

int ops(int *arr, int n)
{
    if(n==1)return 0;
    if(n==2 && arr[0] == arr[1])return 1;
    if(arr[0] > arr[1])
    {
        for(int i=1; i<n; i++)
        {
            if(i%2==0 && arr[i-1]>arr[i])
            {
                arr[i] = arr[i-1] +1;
                c+= arr[i] - arr[i-1];
            }
        }
    }
    if(arr[0]<arr[1])
    {
        for(int i=1; i<n; i++)
        {
            


int main()
{

}

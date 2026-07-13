#include<stdio.h>

long long max_score(int *nums, int size)
{
    int total=0, i, pre, suf;
    int *arr = (int *)malloc(size*sizeof(int));
    for(i=0; i<size; i++)
    {
        total += nums[i];
        arr[i] = total;
    }
    for(i=0; i<size-1; i++)
    {




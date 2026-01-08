#include<stdio.h>
#include<stdlib.h>
void print(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int *error_num(int *arr, int n)
{
    int num;
    int *ans = (int *)malloc(2*sizeof(int));
    int *test = (int *)malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        num = arr[i];
        test[num-1]++;
    }
    print(test, n);
    for(int i=0; i<n; i++)
    {
        if(test[i]>1)ans[0] = i+1;
        if(test[i]==0)ans[1] = i+1;
    }
    print(ans, 2);
    free(test);
    return ans;
}

int main()
{
    int arr[] = {1,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    error_num(arr, size);
   
}



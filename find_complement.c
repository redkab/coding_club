#include<stdio.h>
#include<stdlib.h>
void print(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}
int comp(int num)
{
    int arr[32] = {0};
    int i;
    for(i=0; num; i++)
    {
        arr[i] = num%2;
        num /= 2;
        //printf("i is %d\n", i);
    }
    print(arr, 32);
    int rev = 0;
    for(int j=0; j<i; j++)
    {
        rev = rev *2 +(arr[j] + 1)%2;
    }
    return rev;
}

int main()
{
    printf("%d\n", comp(2));
}


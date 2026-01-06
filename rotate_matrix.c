#include<stdio.h>

void print(int matrix[][4], int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void rotate(int arr[][4], int n)
{
    int i,j, temp;
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[j][i];
            arr[j][i] = temp;
        }
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<n/2; j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[i][n-1-j];
            arr[i][n-1-j] = temp;
        }
    }
}

int main()
{
    int arr[][4] = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    print(arr, 4);
    rotate(arr, 4);
    print(arr, 4);
}

#include<stdio.h>

int max_sum(int matrix[][3], int n)
{
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(matrix[i][j] <0)
            {
                neg++;
                sum += -matrix[i][j];
            }
            else sum += matrix[i][j];
            if(matrix[i][j]<min)min = matrix[i][j];
        }

    }
            

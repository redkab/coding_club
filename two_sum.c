#include<stdio.h>

int main()
{
    int x[] = {1, 3, 4,5 ,7,8};
    int target;
    printf("Enter target\n");
    scanf("%d", &target);
    int i, j;
    int size = sizeof(x)/sizeof(x[0]);
    for(i=0; i<size; i++)
    {
        for(j=0; j<size; j++)
        {
            if (x[i] + x[j] == target && i != j)
            {
                printf("[%d, %d]\n", x[i], x[j]);
            }
        }
    }
}



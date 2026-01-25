#include<stdio.h>
#include<stdlib.h>

int reverse(int *arr, int l, int r)
{
    for(int i=l;i<=(l+r)/2 ; i++)
    {
        //swap(arr[l+i], arr[r-i])
        int temp = arr[l+i];
        arr[l+i] = arr[r-i];
        arr[r-i] = temp;
    }
}
void print(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void solve(int *arr, int n)
{
    printf("entered solve\n");
    if(arr[0] != n)
    {
        int l,r=-1;
        for(int i=1; i<n; i++)
        {
            if(arr[i] == n)
            {
                r=i;
                break;
            }
        }
        reverse(arr, 0, r);
        //print(arr, n);
        return ;
    }
    solve(arr+1, n-1);

}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        int *arr = (int *)malloc(n*sizeof(int));
        for(int i=0; i<n; i++)
        {
            scanf("%d", &arr[i]);
        }
        solve(arr, n);
        print(arr, n);
        free(arr);
    }
}

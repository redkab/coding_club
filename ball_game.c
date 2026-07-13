#include<stdio.h>
#include<stdlib.h>

int no(char *s, int n)
{
    int *arr = (int *)calloc(n, sizeof(int));
    int curr = 0;
    for(int i=0; s[i]; i++)
    {
        arr[curr]++;
        if(s[i] == 'R')
        {
            if(curr == n-1)curr = 0;
            else curr++;
        }
        if(s[i] == 'L')
        {
            if(curr == 0)curr = n-1;
            else curr--;
        }
    }
    int c=0;
    for(int i=0; i<n; i++)
    {
        if(arr[i])c++;
    }
    return c;
}

int main()
{
    char s[] = "RRLRRRRRL";
    int n=9;
    printf("%d\n", no(s,n));
}


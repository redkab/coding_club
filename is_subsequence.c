#include<stdio.h>

int is_subsequence(char s[], char t[], int size_t)
{
    int i,j;
    int k=0, count = 0;
    for(i=0; t[i] != '\0'; i++)
    {
        for(j=k; s[j] != '\0'; j++)
        {
            if(s[j] == t[i])
            {
                k=i; 
                count++;
            }
        }
    }
    return count == size_t;
}

int main()
{
    char s[] = "cdfdsg";
    char t[] = "adfg";
    int size_t = sizeof(t)/sizeof(t[0]) - 1;
    int x = is_subsequence(s, t, size_t);
    printf("%d\n", x);
}

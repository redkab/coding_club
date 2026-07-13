#include<stdio.h>

char *longestcommonPrefix(char **strs, int strsSize)
{
    char s[200];
    int i,j;
    char x;
    for(i=0; i<200; i++)
    {
        x = strs[0][i];
        for(j=1; j<strsSize; j++)
        {
            if(x!=strs[j][i])return s;
        }
        s[i] = x;
    }
}

int main()
{
    char s[][] = {"flow", "flower", "flour"};
    printf("%s\n", longestCommonPrefix(s, 3));
}




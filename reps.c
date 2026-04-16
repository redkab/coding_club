#include<stdio.h>
#include<stdlib.h>
int repCount(char *s)
{
    int maxa=0, maxc=0, maxg=0, maxt=0, max=1;
    int currLen=1;
    char curr = s[0];
    for(int i=1; s[i]; i++)
    {
        if(s[i] == curr)
        {
            currLen++;
            if(currLen > max)max = currLen;
        }
        else
        {
            curr = s[i];
            currLen=1;
        }
    }
    return max;
}


int main()
{
    char *s = (char *)malloc(1000001);
    scanf("%s", s);
    printf("%d", repCount(s));
}


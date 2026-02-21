#include<stdio.h>
#include<stdlib.h>
int score(char *s, int n)
{
    char x;
    int c=1;
    if(!n)return 0;
    x = s[0];
    for(int i=0; s[i]; i++)
    {
        if(s[i]!=x)
        {
            x = s[i];
            c++;
        }
    }
    return c;
}

int main()
{

    int t;
    scanf("%d", &t);
    while(t--)
    {
        int n;
        scanf("%d", &n);
        char *s = (char *)malloc((n+1)*sizeof(char));
        scanf("%s", s);
        s[n] = '\0';
        if(s[0] != s[n-1] && s[n-1] == s[n-2])printf("%d\n", score(s, n)+1);
        else printf("%d\n", score(s, n));
    }
}

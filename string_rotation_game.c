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
void rotate(char *s, int n)
{
    char buff = s[0];
    for(int i=0; i<n; i++)
    {
        s[i] = s[i+1];
    }
    s[n] = buff;
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
        int max=0, p;
        for(int i=0; i<n; i++)
        {
            p = score(s,n);
            if(p>max)max=p;
            rotate(s,n);
        }
        printf("%d\n", max);
        free(s);
    }

}

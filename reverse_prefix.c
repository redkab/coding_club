#include<stdio.h>

char *rev(char *s, int k)
{
    char temp;
    for(int i=0; i<k/2; i++)
    {
        temp = s[i];
        s[i] = s[k-1-i];
        s[k-1-i] = temp;
    }
    return s;
}


int main()
{
    char s[] = "xyz";
    printf("Original is %s\n", s);
    rev(s, 1);
    printf("New is %s\n", s);
}


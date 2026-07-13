#include<stdio.h>
#include<stdlib.h>

int id(char *s)
{
    int prod = 0, num;
    for(int i=0; s[i] != ':'; i++)
    {
        int num = s[i] - '0';
        prod = prod*10+num;
    }
    return prod;
}


int main()
{
    printf("%d\n", id("123:opo"));
}



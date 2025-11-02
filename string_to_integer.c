#include<stdio.h>

int myAtoi(char s[])
{
    int i,num=0, sign=1, digit, count=0, end;
    printf("Entered myAtoi with %s\n", s);
    for(i=0; s[i] != '\0'; i++)
    {
        if(s[i] == '+') sign = 1;
        if(s[i] == '-') sign = -1;
    }
    for(i=0; s[i] != '\0'; i++)
    {
        if(s[i] <= '9' && s[i] >= '0')
        {
            digit = s[i] - '0';
            num = num*10 + digit;
            count++;

        }
        if(s[i] > '9' || s[i] <'0')
        {
            if(count >0)
            {
                return sign*num;
            }
        }
    }
    
    return sign*num;
}




int main()
{
    char num[] = "-042ab3";
    printf("%d\n", myAtoi(num));
}


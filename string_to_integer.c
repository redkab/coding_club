#include<stdio.h>

int myAtoi(char s[])
{
    int i,num=0, sign=0, digit, start, end;
    for(i=0; s[i] != '\0'; i++)
    {
        if(s[i] == '+') sign = 1;
        if(s[i] == '-') sign = -1;
        if(s[i] == '0' && s[i+1] !='0') 
        {
            start = i+1;
            break;
        }
    }
    for(i=0; s[i] != '\0'; i++);
    end = i-1;
    printf("Sign is %d, start is %d, end is %d\n", sign, start, end);
    for(i=start; i<=end; i++)
    {
        digit = s[i] - '\0' -'0';
        num = num*10 + digit;
    }
    return sign*num;
}




int main()
{
    char num[] = "-00042";
    myAtoi(num);
    printf("%d\n", myAtoi(num));
}


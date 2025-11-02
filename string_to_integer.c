#include<stdio.h>

int myAtoi(char s[])
{
    int i,num=0, sign=1, digit, start, end;
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
        }
    }
    
    return sign*num;
}




int main()
{
    char num[] = "-042";
    char *nums[] = {"-042", "        55", "       -0056", "-0000566", "abc123", "-abc246", "234abc"};
    int i;
    printf("%d\n", myAtoi(num));
    for(i=0; i<sizeof(nums)/sizeof(num[0]); i++)
    {
        printf("%d %d\n", i, myAtoi(nums[i]));
    }
     
}


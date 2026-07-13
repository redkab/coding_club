#include<stdio.h>
#include<stdlib.h>
int power(int base, int exp)
{
    int i=0;
    int prod=1;
    for(i=0; i<exp; i++)
    {
        prod*= base;
    }
    return prod;
}
char **combinations(char *digits, int *returnSize)
{
    int fc=0, tc=0;
    int i, digit;
    for(i=0; digits[i] != '\0'; i++)
    {
        digit = digits[i] - '0';
        if(digit == 7 || digit == 9)
        {
            fc++;
        }
        else tc++;
    }
    int count = power(4, fc) * power(3, tc);
    tc=2, fc=3;
    char **combos = malloc(count*(sizeof(char *)));
    for(i=0; i<count; i++)
    {
        combos[i] = malloc((tc+fc)*sizeof(char));
    }
    combos[2] = "bruhrhurhr";
    printf("%s\n", combos[2]);
}




int main()
{
    char arr[] = "23";
    int ok;
    combinations(arr, &ok);
}




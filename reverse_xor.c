#include<stdio.h>

int rev_binary(int decimal)
{
    int rem, q=decimal, sum=0;
    while(q)
    {
        rem = q%2;
        q /= 2;
        sum = sum*10 + rem;
    }
    return sum;
}

int decimal(int binary)
{
    int val=1;
    int digit;
    int temp = binary;
    int sum=0, rem;
    while(temp)
    {
        rem = temp%10;
        digit = rem*val;
        sum  += digit;
        val *= 2;
        temp /= 10;
        printf("Sum is %d\n", sum);
    }
    return sum;
}
int reverse_xor(int x)
{
    int y = decimal(rev_binary(x));
    return x^y;
}


int main()
{
    printf("%d\n", rev_binary(34));
    printf("%d\n", decimal(10101));
    printf("%d\n", reverse_xor(3));
}

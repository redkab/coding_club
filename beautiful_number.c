#include<stdio.h>

int digit_freq(int n, int digit)
{
    int temp = n;
    int d;
    int count = 0;
    while(temp>0)
    {
        d = temp%10;
        if(d == digit) count++;
        temp /= 10;
    }
    return count;
}

int is_beautiful(int n)
{
    int temp = n;
    int digit,freq;
    while(temp>0)
    {
        digit = temp%10;
        freq = digit_freq(n, digit);
        if(freq != digit) return 0;
        temp /= 10;
    }
    return 1;
}

int main()
{
    printf("%d\n", is_beautiful(1323));
}

    

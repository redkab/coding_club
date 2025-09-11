#include<stdio.h>

int is_palindrome(int x)
{
    int rem=0;
    int copy = x;
    int reverse=0; 
    //printf("Entered is_palindrome with x = %d\n", x);
    if(x < 0)
    {
        return 0;
    }

    while(x > 0)
    {   
        rem = x % 10;
        reverse = 10 * reverse + rem;
        x = x / 10;

    }   
    //printf("Reverse is %d and copy is %d\n", reverse, copy);
    return reverse == copy;

}  
int main()
{
    int x;
    int y;
    printf("Enter the number\n");
    scanf("%d", &x);
    y = is_palindrome(x);
    //printf("Y is %d\n", y);
    if (y)
    {
        printf("It is a palindrome\n");
    }
    else
    {
        printf("No it is not a palindrome\n");
    }
}






#include<stdio.h>

int is_palindrome(int x)
{
    int rem=0;
    int reverse=0;
    if(x<0)
    {   
      x = x * -1; 
    }   

    
    while(x > 0)
    {   
      rem = x%10;
       reverse = 10*reverse + rem;
    x = x/10;
    }   
    if(x<0)
    {   
    reverse= reverse * -1;
    }
    if(reverse == x)
    {
   return 1;
    }
    else
    {
   return 0;
    }

}  
int main()
{
    int x;
    int y;
    printf("Enter the number\n");
    scanf("%d", &x);
    y = is_palindrome(x);
    if (y == 1)
    {
        printf("It is a palindrome");
    }
    else
    {
        printf("No it is not a palindrome");
    }
}






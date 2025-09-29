#include<stdio.h>
#include<string.h>
void str_rev_cpy(char a[], char b[])
{
    int i, length = strlen(a);
    for(i=0; i<length; i++)
    {
    b[i] = a[length - 1 - i];
    }
}




int main()
{
    char a[100] = "Hello";
    char b[100];
    int i,length;
    char temp;
  /*  length = strlen(a);
    for(i=0; i<length/2; i++)
    {
      temp = a[i];
      a[i] = a[length-1 - i];
      a[length - i-1] = temp;
    }*/
    str_rev_cpy(a, b);
    printf("%s\n", b);
}


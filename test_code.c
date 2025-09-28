#include<stdio.h>

void random(char a[], char b[])
{
    while(*a++=*b++);

}
int main()
{
    char a[100] = "Hello";
    char b[100] = "Bye";
    random(a, b);
    printf("%s\n", a);
    printf("%s\n", b);
}

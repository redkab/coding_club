#include<stdio.h>
int is_alpha(char x);
int is_digit(char x);
int is_alnum(char x)
{
    return is_alpha(x) || is_digit(x);
}
int is_upper(char x)
{
    return x >= 'A' && x <= 'Z';
}
int is_lower(char x)
{
    return x >= 'a' && x <= 'z';
}
int to_upper(char x)
{
    if(is_lower(x))
    {
        return x - 'a' + 'A';
    }
    return x;
}
int to_lower(char x)
{
    if(is_upper(x))
    {
        return x - 'A' + 'a';
    }
    return x;
}

int is_alpha(char x)
{
    if(x >= 'A' && x <= 'Z')
    {
        return 1;
    }
    if(x >= 'a' && x <= 'z')
    {
        return 1;
    }
    return 0;
}

int is_digit(char x)
{
    return x >= '0' && x <= '9';
}


int tests()
{

    printf("%d\n", is_alnum('S'));
    printf("%d\n", is_alnum('f'));
    printf("%d\n", is_alnum('\n'));
    printf("%d\n", is_alnum(' '));
    printf("%d\n", is_alnum('!'));
    printf("%c\n", to_upper('a'));
    printf("%c\n", to_upper('A'));
    printf("%c\n", to_upper('0'));
    printf("%c\n", to_lower('B'));
    printf("%c\n", to_lower('s'));
    printf("%c\n", to_lower('2'));
}
int remove_punctuation(char s[])
{
    int i=0, j=0;
    char ch;
    for(i=0; s[i] != '\0'; i++)
    {
        if(is_alnum(s[i]))
        {
            s[j] = to_lower(s[i]);
            j++;
        }
    }
    s[j] = '\0';
}

int is_palindrome(char s[])
{
    int i, length=0;
    for(length=0; s[length] != '\0'; length++)
    {
    }
    printf("Length is %d\n", length);
    for(i=0; i < length/2; i++)
    {
        if(s[i] != s[length - 1 -i])
        {
            return 0;
        }
    }
    return 1;
} 

int main()
{
    char s[] =  "A man, a plan, a canal: Panama";
    char t[] = "race a car";
    remove_punctuation(s);
    printf("s = %s\n", s);
    printf("%d\n", is_palindrome(s));
    remove_punctuation(t);
    printf("t = %s\n", t);
    printf("%d\n", is_palindrome(t));
}


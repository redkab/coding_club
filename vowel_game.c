#include<stdio.h>

int vowel_count(char word[], int size)
{
    int i;
    int count = 0;
    for(i=0; i<size; i++)
    {
        if(word[i] == 'a' | word[i] == 'e' | word[i] == 'i' | word[i] == 'o' | word[i] == 'u')
        {
            count++;
        }
    }
    return count;

}

int main()
{
    int count;
    char word[] = "hello";
    int size = sizeof(word)/sizeof(word[0]) - 1;
    count = vowel_count(word, size);
    printf("%d\n", count);
}


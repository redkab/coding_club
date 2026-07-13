#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int searcher(char *s, int len, char **dict, int size)
{
    char a[50];
    printf("entered with %s\n", a);
    for(int i=0; i<len; i++)
    {
        a[i] = s[i];
    }
    for(int i=0; i<size; i++)
    {
        if(strcmp(a, dict[i])==0) return 1;
    }
    return 0;
}
int wordBreak(char *s, char **dict, int size)
{
    int split;
    printf("s is %s\n", s);
    if(s[0] == '\0') return 1;
    for(split=1; split<strlen(s); split++)
    {

        if(searcher(s, split, dict, size))
        {
            wordBreak(s+split, dict, size);
        }
    }
    return 0;
}

int main()
{
    char *dict[30] = {"hi", "car", "pet", "ant", "apple", "dog", "cat", "pen", "candy"};
    char s[] = "carcandy";
    printf("%d\n", wordBreak(s, dict, 9));
}  



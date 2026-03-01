#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int wordPattern(char *p, char *s)
{
    char word[301];
    int ind,sp=0;
    char x[26][301];
    for(ind = 0; p[ind]; ind++)
    {
        int i,k=0;
        printf("sp is %d\n", sp);
        for( i=sp; s[i] != ' ' && s[i] !='\0'; i++)
        {
            word[k++] = s[i];
        }
        word[k] = '\0';
        printf("Current word is %s\n", word);
        sp=i+1;
        if(strlen(x[p[ind]-'a'])==0)
        {
            strcpy(x[p[ind]-'a'], word);
        }
        else
        {
            if(strcmp(x[p[ind]-'a'], word)!=0)return 0;
        }
    }
    return 1;
}

int main()
{
    char p[] = "abbc";
    char s[] = "dog cat cat fish";
    printf("%d\n", wordPattern(p,s));
}

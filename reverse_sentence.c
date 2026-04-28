#include<stdio.h>
#include<stdlib.h>
#include<string.h>



char *reverseWords(char *s)
{
    char arr[1000][100];
    int j=0, k=0;
    for(int i=0; s[i]!='\0'; i++)
    {
        //Making an array of strings....putting each word of the sentence as a string in the array
        if(s[i] != ' ')
        {
        arr[j][k++] = s[i];
        }
        if(s[i] == ' ')
        {
            arr[j][k] = '\0';
            j++;
            k=0;
        }
    }
    //j holds the number of words in our sentence;

    char *ans = (char *)calloc(strlen(s)+1, 1);//allocating a blank string to hold the ans
    for(int i=j; i>=0; i--)
    {
        strcat(ans, arr[i]);
        strcat(ans, " ");
    }
    return ans;
}




int main()
{
    char sentence[] = "My name is Saketh";
    printf("%s\n", reverseWords(sentence));
}

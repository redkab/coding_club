#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int f(char s[], int x)
{
    //printf("Entered with x = %d\n", x);
    int arr[26] = {0};
    for(int i=0; i<x; i++)
    {
        int a = s[i] - 'a';
        arr[a]++;
    }
    int total=0;
    for(int i=0; i<26; i++)
    {
        if(arr[i] !=0) total++;
    }
    return total;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int len; 
        scanf("%d", &len);
        char *s = (char *)malloc((len+1)*sizeof(char));
        scanf("%s", s);
        int split, max=0, y;
        for(split = 1; split<len; split++)
        {
            y = f(s, split) + f(s+split, len-split);
            if(y>max) max = y;
        }
        printf("%d\n", max);
        free(s);
    }
    return 0;

}

int mai()
{
    char s[] = "a";
    printf("%d\n", f(s, 1));
}


#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack 
{
    int arr[10000];
    int top;
}stack;

int push(stack *s, int x)
{
    s->arr[++(s->top)] = x;
    return 1;
}

int pop(stack *s, int *x)
{
    if(s->top==-1)return 0;
    *x = s->arr[(s->top)--];
    return 1;
}

int good(char *str, stack *s)
{
    int x;
    for(int i=0; str[i]; i++)
    {
        if(s->top!=-1 && (int)str[i] == s->arr[s->top])
        {
            pop(s, &x);
        }
        else push(s, (int)str[i]);
    }
    return s->top==-1;
}

int main()
{
    char str[1000];
    scanf("%s", str);
    struct stack s;
    s.top=-1;
    printf("%d\n", good(str, &s));
}


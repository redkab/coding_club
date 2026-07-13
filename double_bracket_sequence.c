#include<stdio.h>
#define CAP 20000

struct stack 
{
    int arr[CAP];
    int top;
};

void init(struct stack *s)
{
    s->top=-1;
}

int push(struct stack *s, char c)
{
    if(s->top == CAP-1)return 0;
    int val = c;
    s->arr[++(s->top)] = val;
    return 1;
}

int pop(struct stack *s, char *y)
{
    if(s->top == -1)return 0;
    char x;
    x = s->arr[(s->top)--];
    *y = x;
    return 1;
}

int main()
{
    int count=0;
    struct stack s;
    init(&s);
    char x; 
    char t[] = "[)";
    for(int i=0; t[i]; i++)
    {
        if(t[i] == '[' || t[i] == '(')
        {
            push(&s, t[i]);
        }
        if(s->top==-1)break;
        if(t[i] == ']')
        {
            pop(&s, &x);
            if(x != '[')count++;
        }
        if(t[i] == ')')
        {
            pop(&s, &x);
            if(x != '(')count++;
        }





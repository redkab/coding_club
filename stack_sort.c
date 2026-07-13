#include<stdio.h>

struct stack
{
    int arr[CAP];
    int top;
};

int is_empty(struct stack *s)
{
    return s->top==-1;
}

void init(struct stack *s)
{
    s->top = -1;
}

int push(struct stack *s, int val)
{
    if(s->top == CAP-1)return 0;
    s->arr[++(s->top)] = val;
    return 1;
}

int pop(struct stack *s, int *val)
{
    if(is_empty(s))return 0;
    *val = s->arr[(s->top)--];
    return 1;
}

void print(struct stack *s)
{


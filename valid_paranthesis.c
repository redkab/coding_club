#include<stdio.h>
#define CAP 1000
struct stack
{
    int arr[CAP];
    int top;
};

void init(struct stack *s)
{
    s->top = -1;
    return;
}

int push(struct stack *s, int val)
{
    if(s->top == CAP-1)return 0;
    s->arr[++(s->top)] = val;
    return 1;
}

int pop(struct stack *s, int *val)
{
    if(s->top == -1)return 0;
    *val = s->arr[(s->top)--];
    return 1;
}

void print(struct stack *s)
{
    for(int i=0; i<=s->top; i++)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
}

int is_empty(struct stack *s)
{
    if(s->top == -1)return 1;
    return 0;
}


int main()
{
    struct stack s;
    init(&s);
    int x;
    char p[1000];
    printf("Enter paranthesis string\n");
    scanf("%s", p);
    for(int i=0; p[i] != '\0'; i++)
    {
        if(p[i] == '{')
        {
            push(&s, 1);
        }
        if(p[i] == '}')
        {
            if(is_empty(&s))
            {
                printf("Not valid\n");
                return 0;
            }
            pop(&s, &x);
        }
    }
    if(is_empty(&s))
    {
        printf("Valid\n");
        return 0;
    }
    printf("Not Valid\n");

}  




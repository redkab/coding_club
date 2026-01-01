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
    int x,y,digit, ans;
    char a[1000];
    printf("Enter the expression\n");
    scanf("%s", a);
    for(int i=0; a[i] != '\0'; i++)
    {
        if(a[i] >='0' && a[i] <='9')
        {
            digit = a[i] - '0';
            push(&s, digit);
           // printf("Pushing %d\n", digit);
            //print(&s);
        }
        if(a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
        {
            pop(&s, &x);
            pop(&s, &y);
            //printf("Popped %d and %d\n", x, y);
            //print(&s);
            switch(a[i])
            {
                case '+':
                    ans = x+y;
                    break;
                case '-':
                    ans = x-y;
                    break;
                case '*':
                    ans = x*y;
                    break;
                case '/':
                    ans = x/y;
            }
            push(&s, ans);
        }
        //printf("Pushing %d\n", ans);
    }
    pop(&s, &x);
    printf("Ans is %d\n", x);
}




#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    char arr[1000];
    int top;
};

int push(struct stack *s, char ele)
{
    s->arr[++(s->top)] = ele;
    return 1;
}

int pop(struct stack *s, char *x)
{
   *x = s->arr[(s->top)--];
    return 1;
}
void init(struct stack *s)
{
    s->top = -1;
}
char* reverseByType(char* t)
{
    struct stack alp, spe;
    init(&alp);
    init(&spe);
    char *ans = (char *)malloc((strlen(t)+1)*sizeof(char));
    //printf("Created stacks and ans string\n");
    for(int i=0; t[i]; i++)
    {
        if(t[i] >= 'a' && t[i] <= 'z')
        {
            push(&alp, t[i]);
        }
        else
        {
            push(&spe, t[i]);
        }
    }
    //printf("Filled stack\n");
    char x;
    for(int i=0; t[i]; i++)
    {
        if(t[i] >= 'a' && t[i] <= 'z')
        {
            pop(&alp, &x);
            ans[i] = x;
        }
        else
        {
            pop(&spe, &x);
            ans[i] = x;
        }
    }
    return ans;
    
}


int main()
{
    char a[1000];
    printf("Enter string\n");
    scanf("%s", a);
    char *ans = reverseByType(a);
    printf("%s\n", ans);
    free(ans);
}


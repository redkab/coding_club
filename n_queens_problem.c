#include<stdio.h>
#include<stdlib.h>
#define CAP 10000
struct stack
{
    int arr[CAP][2];
    int top;
};

int isFull(struct stack *s)
{
    return s->top == CAP-1;
}

int isEmpty(struct stack *s)
{
    return s->top == -1;
}
void init(struct stack *s)
{
    s->top = -1;
}

int push(struct stack *s, int x, int y)
{
    if(isFull(s))return 0;
    s->arr[++(s->top)][0] = x;
    s->arr[s->top][1] = y;
    return 1;
}

int pop(struct stack *s, int *x, int *y)
{
    printf("Entered with top = %d\n", s->top);
    if(isEmpty(s))return 0;
    *x = s->arr[s->top][0];
    *y = s->arr[(s->top)--][1];
    printf("Exited with top = %d\n", s->top);
    return 1;
}

int safe_diags(int **board, int n, int x, int y)
{
    int i,j;
    for(i=x-1, j=y-1; i>=0 && j>=0;i--, j--)
    {

        //printf("Visited %d, %d and value is %d\n", i, j, board[i][j]);
        if(board[i][j])return 0;
    }


    for(i=x+1, j=y+1; i<n && j<n; i++, j++)
    {
        //printf("Visited %d, %d and value is %d\n", i, j, board[i][j]);
        if(board[i][j])return 0;
    }


    for(i=x-1, j=y+1; i>=0 && j<n; i--, j++)
    {
        //printf("Visited %d, %d and value is %d\n", i, j, board[i][j]);
        if(board[i][j])return 0;
    }

    for(i=x+1, j=y-1; i<n && j>=0; i++, j--)
    {
        //printf("Visited %d, %d and value is %d\n", i, j, board[i][j]);
        if(board[i][j]) return 0;
    }
    return 1;
}

int safe_row(int **board,int n, int row, int col)
{
    for(int i=0; i<n; i++)
    {
        if(board[row][i])return 0;
    }
    return 1;
}

int safe_col(int **board, int n, int row, int col)
{
    for(int i=0; i<n; i++)
    {
        if(board[i][col])return 0;
    }
    return 1;
}

int safe(int **b, int n, int r, int c)
{
    if(safe_diags(b, n, r, c) && safe_row(b, n, r, c) && safe_col(b, n, r, c))return 1;
    return 0;
}



void print(int **board, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void stack_print(struct stack *s)
{
    for(int i=s->top; i>=0; i--)
    {
        printf("%d, %d\n", s->arr[i][0], s->arr[i][1]);
    }
    printf("\n");
    printf("Top = %d\n",s->top); 
}

int empty(int **board, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(board[i][j])break;
            if(j==n-1)return i;
        }
    }
    return -1;
}

void undo_and_move(int **board,int n, struct stack *s)
{
    int row, col;
    pop(s, &row, &col);
    printf("Popped row = %d and col = %d\n", row, col);
    board[row][col] = 0;
    if(col+1 <n)
    {
    board[row][++col] = 1;
    push(s, row, col);
    }
    else undo_and_move(board,n,  s);
}
void n_queens(int **board, struct stack *s, int n)
{
    //print(board, n);
    if(empty(board, n)==-1)
    {
        printf("Final board is \n");
        print(board, n);
        exit(1);
    }

    int start = empty(board, n);
    printf("Start row is %d\n", start);
    for(int i=0; i<n; i++)
    {
        if(safe(board, n, start, i))
        {
            board[start][i] = 1;
            push(s, start, i);
            n_queens(board, s, n);
        }
    }
    printf("Undoing\n");
    undo_and_move(board,n, s);
    stack_print(s);
    print(board, n);
    n_queens(board, s, n);
}
int main()
{

    struct stack s;
    init(&s);
    int n=8;
    int **board = (int **)calloc(n, sizeof(int *));
    for(int i=0; i<n; i++)
    {
        board[i] = (int *)calloc(n, sizeof(int));
    }
    n_queens(board, &s, n);

}





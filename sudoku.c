#include<stdio.h>
#include<stdlib.h>
int safe(int **grid, int r, int c, int num)
{
    if(grid[r][c])return 0;
    for(int i=0; i<9; i++)
    {
        if(grid[i][c]==num)return 0;
    }
    for(int i=0; i<9; i++)
    {
        if(grid[r][i]==num)return 0;
    }
    int rstart, cstart;
    if(r<3)rstart=0;
    else
    {
        rstart = ((r/3)+1)*3;
    }
    if(c<3)cstart=0;
    else cstart = ((c/3)+1)*3;

    for(int i= rstart; i<rstart+3; i++)
    {
        for(int j= cstart; j<cstart+3; j++)
        {
            if(grid[i][j] == num)return 0;
        }
    }
    return 1;
}

void print(int **grid)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("_____________________________________\n");
}
void set(int **grid, char *s)
{
    int k=0;
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            grid[i][j] = s[k] - '0';
            k++;
        }
    }
}

int full(int **grid)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(grid[i][j]==0)return 0;
        }
    }
    return 1;
}
int solve(int **grid,  int r, int c)
{
    print(grid);
    if(full(grid))
    {
        printf("Solution is \n");
        print(grid);
        return 1;
    }
    if(r==9)
    {
        solve(grid, 0, 0);
    }
    else if(c==9)solve(grid, r+1, 0);
    else if(grid[r][c] != 0)solve(grid, r, c+1);
    else
    {
        for(int i=1; i<=9; i++)
        {
            if (safe(grid, r, c, i))
            {
                grid[r][c] = i;
                if (solve(grid, r, c+1))return 1;
                else return 0;
            }
        }
    }
}




int main()
{
    int **grid = (int **)calloc(9, sizeof(int *));
    for(int i=0; i<9; i++)
    {
        grid[i] = (int *)calloc(9, sizeof(int));
    }
    char s[] = "072800003030009010901502700620900500150000039009005062007406308040700020300008470";
    set(grid, s);
    solve(grid, 0, 0);
}


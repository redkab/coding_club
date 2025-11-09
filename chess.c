#include<stdio.h>
void board_print(char board[8][8])
{
    int i,j;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}
void zero_set(char board[8][8])
{

    int i,j;
    for(i=0; i<8; i++)
    {
        for(j=0; j<8; j++)
        {
            board[i][j] = ' ';
        }
    }
}
void move(char board[8][8])
{
    int src_row, dest_row;
    char src_clmn, dest_clmn;
    char temp;
    printf("Enter move\n");
    scanf("%c%d %c%d", &src_clmn, &src_row, &dest_clmn, &dest_row);
    //printf("%c%d %c%d\n", src_clmn, src_row, dest_clmn, dest_row);
    
    int arr_src_row, arr_dest_row;
    int arr_src_clmn, arr_dest_clmn;
    arr_src_row = 8 - src_row;
    arr_dest_row = 8 - dest_row;
    arr_src_clmn = src_clmn - 'a';
    arr_dest_clmn = dest_clmn - 'a';
    printf("%d%d %d%d\n", arr_src_clmn, arr_src_row, arr_dest_clmn, arr_dest_row);
    board[arr_dest_row][arr_dest_clmn] = board[arr_src_row][arr_src_clmn];
    board[arr_src_row][arr_src_clmn] = ' ';
    board_print(board);
    
}
void set(char board[8][8])
{
    int i,j;
    for(i=0; i<8; i++)
    {
        board[1][i] = 'P';
        board[6][i] = 'p';
    }
    board[0][0] = 'R';
    board[0][7] = 'R';
    board[7][0] = board[7][7] = 'r';
    board[0][1] = board[0][6] = 'N';
    board[7][1] = board[7][6] = 'n';
    board[0][2] = board[0][5] = 'B';
    board[7][2] = board[7][5] = 'b';
    board[0][3] = 'Q';
    board[7][3] = 'q';
    board[0][4] = 'K';
    board[7][4] = 'k';
 
}
int main()
{
    char board[8][8];
    zero_set(board);
    set(board);
    board_print(board);
    move(board);
}


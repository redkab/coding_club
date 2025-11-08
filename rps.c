#include<stdio.h>
#include<stdlib.h>

int main()
{
    char input;
    int comp_score=0, player_score=0;
    int comp_play;
    char pc_play;
    int win;
    printf("How many points to win?\n");
    scanf("%d", &win);
    while(1)
    {
        
        printf("Enter r, p or s\n");
        scanf("%c", &input);
        comp_play = rand()%3;
        switch (comp_play)
        {
            case 0:
                pc_play = 'r';
                break;
            case 1:
                pc_play = 'p';
                break;
            case 2:
                pc_play = 's';
                break;
        }
        if(input == 'r')
        {
            if(pc_play == 'p')comp_score++;
            if(pc_play == 's')player_score++;
        }
        if(input == 'p')
        {
            if(pc_play == 'r') player_score++;
            if(pc_play == 's') comp_score++;
        }
        if(input == 's')
        {
            if(pc_play == 'r') comp_score++;
            if(pc_play == 'p') player_score++;
        }
        printf("You played %c and computer played %c\n", input, pc_play);
        printf("Your Score: %d          Computer Score: %d\n", player_score, comp_score);
        if(player_score == win)
        {
            printf("You Win!\n");
            break;
        }
        if(comp_score == win)
        {
            printf("Computer Wins!\n");
            break;
        }
    }
}

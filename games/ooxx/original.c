#include <stdio.h>
#include <stdlib.h>
void place(int a, int *x, int *y)
{
    switch(a)
    {
        case 1: *x = 4; *y = 0; break;
        case 2: *x = 4; *y = 2; break;
        case 3: *x = 4; *y = 4; break;
        case 4: *x = 2; *y = 0; break;
        case 5: *x = 2; *y = 2; break;
        case 6: *x = 2; *y = 4; break;
        case 7: *x = 0; *y = 0; break;
        case 8: *x = 0; *y = 2; break;
        case 9: *x = 0; *y = 4; break;
        default: *x = *y = -1; break;
    }
}
void reset(char *b)
{
    for(int i = 0; i < 5; i++)//reset
                for(int j = 0; j < 5; j++)
                {
                    if(i % 2 == 1 && j % 2 == 1)
                        *(b + 5 * i + j) = '+';
                    else if(i %2 == 1)
                        *(b + 5 * i + j)= '-';
                    else if(j %2 == 1)
                        *(b + 5 * i + j) = '|';
                    else
                        *(b + 5 * i + j) = ' ';
                }
}
int winorlose(char *board, int count, int turn)
{
    int e = 0;
    for(int i = 0; i < 5; i += 2)
        {
            if(*(board + 5 * i) == *(board + 5 * i + 2) && *(board + 5 * i + 2) == *(board + 5 * i + 4) && count <= 5 && *(board + 5 * i) != ' ')//橫的
            {
                if(turn == 0)
                {
                    printf(" X Win !!\n");
                    e = 1;
                }
                else
                {
                    printf(" O Win !!\n");
                    e= 1;
                }
            }
            if(*(board + i) == *(board + 5 * 2 + i) && *(board + 5 * 2 + i) == *(board + 5 * 4 + i) && count <= 5 && *(board + i) != ' ')//直的
            {
                if(turn == 0)
                {
                    printf(" X Win !!\n");
                    e = 1;
                }
                else
                {
                    printf(" O Win !!\n");
                    e = 1;
                }
            }
        }
    if(*board == *(board + 2 * 5 + 2) && *(board + 2 * 5 + 2) == *(board + 5 * 4 + 4) && count <= 5 && *board != ' ')//斜的
        {
            if(turn == 0)
            {
                printf(" X Win !!\n");
                e = 1;
            }
            else
            {
                printf(" O Win !!\n");
                e = 1;
            }
        }
        if(*(board + 4) == *(board + 2 * 5 + 2) && *(board + 2 * 5 + 2) == *(board + 4 * 5) && count <= 5 && *(board + 4) != ' ')//斜的
        {
            if(turn == 0)
            {
                printf(" X Win !!\n");
                e = 1;
            }
            else
            {
                printf(" O Win !!\n");
                e = 1;
            }
        }
    return e;
}
int  Ai_easy(int a)
{
    int r = rand() % 9 + 1;
    return r;
}
int main()
{
    char board[5][5] = {0};
    reset(&board);
    int cantrol;
    int turn  = 0;
    int count = 9;
    printf("Please enter 1~9 , 0 = reset.\n");
    while(scanf("%d", &cantrol) != EOF)
    {
        count--;
        if(cantrol == 0)
        {
            reset(&board);
            count = 9;
            continue;
        }
        if(count == -1)
        {
            count = 9;
            reset(&board);
        }
        //選擇位子
        int x, y;
        place(cantrol, &x, &y);
        if(x == -1 || y == -1)
        {
            printf("Please enter it again.\n");
            continue;
        }
        //O的回合
        if(turn == 0)
        {
            if(board[x][y] != ' ')
            {
                printf("Please enter it again.\n");
                continue;
            }
            board[x][y] = 'O';
            turn = 1;
        }
        //X的回合
        else if(turn == 1)
        {
            if(board[x][y] != ' ')
            {
                printf("Please enter it again.\n");
                continue;
            }
            board[x][y] = 'X';
            turn = 0;
        }
        //輸出結果
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                printf("%c", board[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        //判斷輸贏
        int end = winorlose(&board, count, turn);
        if(end == 1)
        {
            reset(&board);
            count = 9;
        }

    }

    return 0;
}

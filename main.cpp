#include <curses.h>
#include <stdio.h>
#include <string.h>
#include "Pong.h"

// Written by wak

// TODO:
// create working application exit

void initializeGame(int bh, int bw, int bs)
{
    initscr();
    noecho();
    Pong Board(bh, bw, bs);
    Board.startGame();
    endwin();
}

int main(int argc, char *argv[])
{
    if(argc == 1)
    {
        initializeGame(25, 90, 80);
        printf("Thanks for playing!\n");
    }
    else if(argc == 4)
    {
        int boardWidth = atoi(argv[2]);
        int boardHeight = atoi(argv[3]);
        int ballSpeed = atoi(argv[4]);

        if(boardWidth >= 11 && boardHeight >= 5 && ballSpeed>=10)
        {
            initializeGame(boardHeight, boardWidth, ballSpeed);
            printf("Thanks for playing!\n");
        }
        else printf("Provide valid arguments.\n");
    }
    else if(argc == 2)
    {
        if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0)
        {
            printf("\nPong by wak, written in C++ using PDCurses.\n\n");
            printf("Options:\n\n");
            printf("-bw board-width [min. 8; default 90]\n");
            printf("-bh board-height [min. 15; default 25]\n");
            printf("-bs ball-speed [min. 10 (the fastest one); default 80]\n\n");
            printf("Enjoy.\n");
        }
    }
    else printf("Provide valid arguments.\n");
    fflush(stdout);

    return 0;
}

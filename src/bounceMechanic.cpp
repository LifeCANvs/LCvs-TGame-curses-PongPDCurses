#include "Pong.h"

#include <time.h>
#include <stdlib.h>

void Pong::moveBall()
{
    while(gameActive)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(Ball.speed));

        switch(Ball.direction)
        {
        case 0: // 0 -> down, right
            Ball.y++;
            Ball.x++;
            if(Ball.x == Player2.playerX-1)
                bounceLeft();
            else if(Ball.x >= boardWidth-1)
            {
                Player2.points++;
                Ball.resetVariables();
            }
            else if(Ball.y >= boardHeight - 2)
                Ball.direction = 1;
            break;

        case 1: // 1 -> up, right
            Ball.y--;
            Ball.x++;
            if(Ball.x == Player2.playerX-1)
                bounceLeft();
            else if(Ball.x >= boardWidth-1)
            {
                Player1.points++;
                Ball.resetVariables();
            }
            else if(Ball.y <= 1)
                Ball.direction = 0;
            break;

        case 2: // 2 -> down, left
            Ball.y++;
            Ball.x--;
            if(Ball.x == Player1.playerX+1)
                bounceRight();
            else if(Ball.x <= 0)
            {
                Player2.points++;
                Ball.resetVariables();
            }
            else if(Ball.y >= boardHeight - 2)
                Ball.direction = 3;
            break;

        case 3: // 3 -> up, left
            Ball.y--;
            Ball.x--;
            if(Ball.x == Player1.playerX+1)
                bounceRight();
            else if(Ball.x <= 0)
            {
                Player1.points++;
                Ball.resetVariables();
            }
            else if(Ball.y <= 1)
                Ball.direction = 2;
            break;
        }
    }
}

void Pong::bounceLeft()
{
    //cant use switch because of constant expression
    if(Ball.y == Player2.playerHeight || Ball.y == Player2.playerHeight -1)
        Ball.direction = 3;
    else if (Ball.y == Player2.playerHeight+1)
    {
        srand(time(NULL));
        Ball.direction = rand()%2 + 2;
    }
    else if(Ball.y == Player2.playerHeight+2|| Ball.y == Player2.playerHeight +3)
        Ball.direction = 2;
}

void Pong::bounceRight()
{
    //cant use switch because of constant expression
    if(Ball.y == Player1.playerHeight  || Ball.y == Player1.playerHeight -1)
        Ball.direction = 1;
    else if (Ball.y == Player1.playerHeight+1)
    {
        srand(time(NULL));
        Ball.direction = rand()%2;
    }
    else if(Ball.y == Player1.playerHeight+2 || Ball.y == Player1.playerHeight +3)
        Ball.direction = 0;
}

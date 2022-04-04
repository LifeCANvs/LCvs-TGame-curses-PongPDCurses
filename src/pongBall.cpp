#include "pongBall.h"

#include <time.h>
#include <stdlib.h>

pongBall::pongBall()
{

}

pongBall::~pongBall()
{
    //dtor
}

void pongBall::construct(int x, int y, int ballSpeed)
{
    startX = x;
    startY = y;
    defaultSpeed = ballSpeed;
    resetVariables();
}

int pongBall::randomizeDirection()
{
    srand(time(NULL));
    return rand() % 4;
    // 0 -> down, left
    // 1 -> down, right
    // 2 -> up, left
    // 3 -> up, right
}

void pongBall::resetVariables()
{
    y = startY;
    x = startX;
    speed = defaultSpeed;
    direction = randomizeDirection();
}



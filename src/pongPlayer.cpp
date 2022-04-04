#include "pongPlayer.h"

pongPlayer::pongPlayer()
{

}

pongPlayer::~pongPlayer()
{
    //dtor
}

void pongPlayer::moveUp()
{
    if(playerHeight > 1)
        playerHeight--;
}

void pongPlayer::moveDown()
{
    if(playerHeight < boardHeight-4)
        playerHeight++;
}

void pongPlayer::construct(int y, int x, int bHeight)
{
    playerHeight = y;
    playerX = x;
    boardHeight = bHeight;
    points = 0;
}

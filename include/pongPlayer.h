#ifndef PONGPLAYER_H
#define PONGPLAYER_H


class pongPlayer
{
    public:
        pongPlayer();
        virtual ~pongPlayer();
        int playerHeight, points, playerX, boardHeight;
        void moveUp();
        void moveDown();
        void construct(int, int, int);
};

#endif // PONGPLAYER_H

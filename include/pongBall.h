#ifndef PONGBALL_H
#define PONGBALL_H


class pongBall
{
    public:
        pongBall();
        virtual ~pongBall();
        int startX, startY, x, y, direction, speed, defaultSpeed;
        int randomizeDirection();
        void resetVariables();
        void construct(int, int, int);
};

#endif // PONGBALL_H

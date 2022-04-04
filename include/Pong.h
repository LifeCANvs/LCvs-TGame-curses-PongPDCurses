#ifndef PONG_H
#define PONG_H

#include <curses.h>
#include <thread>

#include "pongPlayer.h"
#include "pongBall.h"

class Pong
{
    public:
        Pong(int , int, int);
        virtual ~Pong();

        int boardHeight, boardWidth;
        const int gameSpeed = 10; //miliseconds
        bool gameActive;
        pongBall Ball;
        pongPlayer Player1, Player2;
        WINDOW *gameWin;
        WINDOW *scoreWin;
        WINDOW *infoWindow;

        std::thread printFrame;
        std::thread playerInput;
        std::thread ballMechanic;
        std::thread speedUpMechanic;

        void startGame();
        void printWindow();
        void printScoreWindow();
        void printInfoWindow();
        void printPlayer(pongPlayer&, int);
        void printBall();
        void movePlayers();

        void moveBall();
        void speedUpBall();
        void bounceRight();
        void bounceLeft();

};

#endif // PONG_H

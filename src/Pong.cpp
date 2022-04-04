#include "Pong.h"

#include <string>

#define ESC 27

Pong::Pong(int height, int width, int ballSpeed)
{
    gameActive = true;

    boardHeight = height;
    boardWidth = width;

    gameWin = newwin(boardHeight, boardWidth, 0, 1);
    scoreWin = newwin(3, boardWidth, boardHeight, 1);
    infoWindow = newwin(1, boardWidth, boardHeight+3, 1);

    Ball.construct((boardWidth-2)/2, boardHeight/2, ballSpeed);
    Player1.construct(boardHeight/2-1, 4, boardHeight);
    Player2.construct(boardHeight/2-1, boardWidth-4, boardHeight);
}

Pong::~Pong()
{
    delwin(gameWin);
    delwin(scoreWin);
    delwin(infoWindow);
}

void Pong::startGame()
{
    printFrame = std::thread(&Pong::printWindow, this);
    playerInput = std::thread(&Pong::movePlayers, this);
    ballMechanic = std::thread(&Pong::moveBall, this);
    speedUpMechanic = std::thread(&Pong::speedUpBall, this);

    printFrame.join();
    playerInput.join();
    ballMechanic.join();
    speedUpMechanic.join();
}

void Pong::printWindow()
{
    while(gameActive)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(gameSpeed));

        werase(gameWin);

        box(gameWin, 0, 0);
        printScoreWindow();
        printInfoWindow();
        printBall();
        printPlayer(Player1, 4);
        printPlayer(Player2, boardWidth - 5);

        wrefresh(gameWin);
        refresh();
    }
}

void Pong::printScoreWindow()
{
    box(scoreWin, 0, 0);
    std::string score = std::to_string(Player1.points) + " - " + std::to_string(Player2.points);
    mvwprintw(scoreWin, 1, boardWidth/2 - score.length()+2, score.c_str());
    wrefresh(scoreWin);
}

void Pong::printInfoWindow()
{
    std::string aboutAuthor = "Pong by wak";
    mvwprintw(infoWindow, 0, (boardWidth-aboutAuthor.size())/2, aboutAuthor.c_str());
    wrefresh(infoWindow);
}

void Pong::printPlayer(pongPlayer &Player, int x)
{
    mvwprintw(gameWin, Player.playerHeight, x, "|");
    mvwprintw(gameWin, Player.playerHeight+1, x, "|");
    mvwprintw(gameWin, Player.playerHeight+2, x, "|");
}

void Pong::movePlayers()
{
    while(gameActive)
    {
        int c = getch();

        if(c == 'W' || c == 'w')
            Player1.moveUp();
        else if(c == 'S' || c == 's')
            Player1.moveDown();
        else if(c == 'I' || c=='i')
            Player2.moveUp();
        else if(c== 'K' || c == 'k')
            Player2.moveDown();
        else if(c == ESC)
            gameActive = false;
    }
}

void Pong::printBall()
{
    mvwprintw(gameWin, Ball.y, Ball.x, "@");
}

void Pong::speedUpBall()
{
    while(gameActive)
    {
        std::this_thread::sleep_for(std::chrono::seconds(5));
        if(Ball.speed > gameSpeed)
            Ball.speed-=10;
    }
}

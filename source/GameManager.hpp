#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include "Ball.hpp"
#include "Racket.hpp"

class gameManager {
private:
    int width, height;
    int score1, score2;
    char up1, down1, up2, down2;
    bool endGame;
    Ball* ball;
    Racket* player1;
    Racket* player2;

    void Draw();
    void Input();
    void Logic();
    void ScoreUP(Racket* player);

public:
    gameManager(int w, int h);
    ~gameManager();
    void runGame();
};

#endif
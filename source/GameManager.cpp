#include "GameManager.hpp"
#include <iostream>
#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
using std::cout, std::endl;

bool kbhit() {
    struct termios oldt, newt;
    int ch;
    int oldf;

    // Get terminal settings
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Disable canonical mode and echo
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Set non-blocking read
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    // Check for key press
    ch = getchar();

    // Restore terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin); // Put character back in buffer
        return true;
    }

    return false;
}

gameManager::gameManager(int w, int h) {
    srand(time(0));
    endGame = false;
    up1 = 'w', down1 = 's', up2 = 'i', down2 = 'k';
    score1 = score2 = 0;
    width = w, height = h;
    ball = new Ball(width / 2, height / 2);
    player1 = new Racket(1, height / 2 - 3);
    player2 = new Racket(width - 2, height / 2 - 3);
}

gameManager::~gameManager() {
    delete ball;
    delete player1;
    delete player2;
}

void gameManager::Draw() {
    system("clear");
    cout << "Player1: " << score1 << endl;
    cout << "Player2: " << score2 << endl;

    for (int i = 0; i < width + 2; i++) cout << "_";
    cout << endl;

    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width; i++) {
            if (i == 0) cout << "|";

            if (ball->getX() == i && ball->getY() == j)
                cout << "O";
            else if (player1->isHere(i, j))
                cout << "#";
            else if (player2->isHere(i, j))
                cout << "#";
            else
                cout << " ";

            if (i == width - 1) cout << "|";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++) cout << "-";
    cout << endl;
}

void gameManager::Input() {
    ball->Move();

    if (kbhit()) {
        char current = getchar();
        if (current == up1 && player1->getY() > 0)
            player1->moveUp();
        if (current == up2 && player2->getY() > 0)
            player2->moveUp();
        if (current == down1 && player1->getY() + 4 < height)
            player1->moveDown();
        if (current == down2 && player2->getY() + 4 < height)
            player2->moveDown();
        if (ball->getDirection() == STOP)
            ball->randomDirection();
        if (current == 'x')
            endGame = true;
    }
}

void gameManager::Logic() {
    int ballx = ball->getX(), bally = ball->getY();

    //Left Raquet collision
    if(player1->isHere(ballx-1,bally)){ 
        ball->changeDirection(direction((rand()%3)+4));
    }

    //Right Raquet collision
    if(player2->isHere(ballx+1,bally)){
        ball->changeDirection(direction((rand()%3)+1));
    }

    //bottom wall collision
    if(bally==height-1){
        ball->changeDirection(ball->getDirection()==DOWNRIGHT? UPRIGHT :UPLEFT);
    }

    //top wall collision
    if(bally==0){
        ball->changeDirection(ball->getDirection()==UPRIGHT? DOWNRIGHT :DOWNLEFT);
    }

    //right wall
    if(ballx==width-1){
        ScoreUP(player1);
    }

    //left wall
    if(ballx==0){
        ScoreUP(player2);
    }
}

void gameManager::ScoreUP(Racket* player) {
    if (player == player1)
        score1++;
    else if (player == player2)
        score2++;
    ball->Reset();
    player1->Reset();
    player2->Reset();
}

void gameManager::runGame() {
    while (!endGame) {
        Draw();
        Input();
        Logic();
        usleep(50000);
    }
    cout << "Game stopped!" << endl;
}
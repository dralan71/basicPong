#ifndef BALL_H
#define BALL_H

#include <iostream>

enum direction {STOP = 0, LEFT, UPLEFT, DOWNLEFT, RIGHT, UPRIGHT, DOWNRIGHT};

class Ball {
private:
    int x, y;
    int originalX, originalY;
    direction dir;

public:
    Ball(int xCoordinate, int yCoordinate);
    void Reset();
    void changeDirection(direction newDirection);
    void randomDirection();
    inline int getX() { return x; }
    inline int getY() { return y; }
    inline direction getDirection() { return dir; }
    void Move();
    friend std::ostream& operator<<(std::ostream& o, Ball c);
};

#endif
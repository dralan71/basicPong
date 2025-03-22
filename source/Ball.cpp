#include "Ball.hpp"
#include <cstdlib>
using std::ostream;

Ball::Ball(int xCoordinate, int yCoordinate)
    : originalX(xCoordinate), originalY(yCoordinate), x(xCoordinate), y(yCoordinate), dir(STOP) {}

void Ball::Reset() {
    x = originalX;
    y = originalY;
    dir = STOP;
}

void Ball::changeDirection(direction newDirection) {
    dir = newDirection;
}

void Ball::randomDirection() {
    dir = (direction)((rand() % 6) + 1);
}

void Ball::Move() {
    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UPLEFT:
        x--;
        y--;
        break;
    case UPRIGHT:
        x++;
        y--;
        break;
    case DOWNLEFT:
        x--;
        y++;
        break;
    case DOWNRIGHT:
        x++;
        y++;
        break;
    default:
        break;
    }
}

ostream& operator<<(ostream& o, Ball c) {
    o<<"Ball ["<<c.x<<", "<<c.y<<"]["<<c.dir<<"]";
    return o;
}
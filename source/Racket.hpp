#ifndef RACKET_H
#define RACKET_H

#include <iostream>
using std::ostream;

class Racket {
private:
    int x, y;             // Current position
    int originalX, originalY;  // Starting position

public:
    // Constructors
    Racket();
    Racket(int xCoordinate, int yCoordinate);

    // Reset to original position
    void Reset();

    // Getters
    int getX() const;
    int getY() const;

    // Movement functions
    void moveUp();
    void moveDown();

    // Check if the racket is at a certain position
    bool isHere(int posX, int posY) const;

    // Overloaded << operator to print Racket info
    friend ostream& operator<<(ostream& o, const Racket& r);
};

#endif
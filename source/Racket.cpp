#include "Racket.hpp"

// Default constructor (not used but good practice)
Racket::Racket() : x(0), y(0), originalX(0), originalY(0) {}

// Constructor with initial position
Racket::Racket(int xCoordinate, int yCoordinate) 
    : originalX(xCoordinate), originalY(yCoordinate), x(xCoordinate), y(yCoordinate) {}

// Reset the racket to its original position
void Racket::Reset() {
    x = originalX;
    y = originalY;
}

// Get X coordinate
int Racket::getX() const {
    return x;
}

// Get Y coordinate
int Racket::getY() const {
    return y;
}

// Move racket up (decrease Y position)
void Racket::moveUp() {
    y--;
}

// Move racket down (increase Y position)
void Racket::moveDown() {
    y++;
}

// Check if the racket occupies a specific position
bool Racket::isHere(int posX, int posY) const {
    return (posX == x && (posY >= y && posY < y + 4));  // 4 is the size of the racket
}

// Overloaded << operator to display racket information
ostream& operator<<(ostream& o, const Racket& r) {
    o << "Racket [" << r.x << ", " << r.y << "]";
    return o;
}
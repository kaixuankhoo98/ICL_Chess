#include "EmptyPiece.hpp"
#include <iostream>
using namespace std;

// =========== Construction ================
EmptyPiece::EmptyPiece(string position) : Piece("..", position) {
    setLongName("Empty");
}
EmptyPiece* EmptyPiece::clone() {
    return new EmptyPiece (*this);
}

// ============ Functions ================
bool EmptyPiece::legalMove(std::string newPosition) {
    return false;
}
bool EmptyPiece::legalCapture(std::string newPosition) {
    return false;
}
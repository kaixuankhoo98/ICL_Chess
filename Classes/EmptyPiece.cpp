#include "EmptyPiece.hpp"
#include <iostream>
using namespace std;

// =========== Construction ================
EmptyPiece::EmptyPiece(string position) : Piece("..", position) {}

// ============ Functions ================
bool EmptyPiece::legalMove(std::string newPosition) {
    return false;
}
#include "Piece.hpp"
#include "EmptySquare.hpp"
#include "Position.hpp"
#include "../functions.hpp"
#define INVALID_COLOR_IN_BOARD 1 // ?
using namespace std;

// ===================== Construction ========================
EmptySquare::EmptySquare(string position, Position* boardState) 
    : Piece("..", position, boardState) {} // calling base class constructor
EmptySquare::EmptySquare(string position) 
    : Piece("..", position) {}

bool EmptySquare::legalMove(Position* nextPos) {
    return false;
}
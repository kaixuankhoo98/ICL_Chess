#include "Piece.hpp"
#include "Position.hpp"
#include "../functions.hpp"
#define INVALID_COLOR_IN_BOARD 1
using namespace std;

// ==== BY THE WAY this is an abstract class ===

// Getter functions
int Piece::getColor() const {
    return color;
}
std::string Piece::getName() const {
    return pieceName;
}
std::string Piece::getPos() const {
    return currentPos;
}

// =============== Construction ===============
Piece::Piece(string name, string position, Position* boardState) 
: pieceName(name), currentPos(position), currentState(boardState) {
    // assign color
    if (name[0] == 'w') color = 0;
    if (name[0] == 'b') color = 1;
    if (name == "..") color = 2;
    if (name[0] != 'w' && name[0] != 'b') exit(INVALID_COLOR_IN_BOARD);
} 
// Copy constructor
Piece::Piece(Piece const& copyPiece)
    : pieceName(copyPiece.pieceName), currentPos(copyPiece.currentPos),
    color(copyPiece.color), currentState(copyPiece.currentState) {}

// Assignment overload
Piece& Piece::operator=(Piece const& copyPiece) {
    pieceName = copyPiece.pieceName;
    currentPos = copyPiece.currentPos;
    color = copyPiece.color;
    currentState = copyPiece.currentState;
    return *this;
}


//============= Virtual ===============
// bool Piece::legalMove(Position* nextPos) {
//     return true;
// }
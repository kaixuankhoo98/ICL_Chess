#include "King.hpp"
#include "Piece.hpp"
#include "Position.hpp"
#include "../functions.hpp"
#define INVALID_COLOR_IN_BOARD 1
using namespace std;

bool King::legalMove(Position* nextPos) {
    
    return true;
}

// Construction
King::King(string name, string position, Position* boardState)
    : Piece::Piece(name, position, boardState) {}
// Copy constructor
// King::King(King const& copyPiece) {}
    // : pieceName(copyPiece.pieceName), currentPos(copyPiece.currentPos),
    // color(copyPiece.color), type(copyPiece.type), currentState(copyPiece.currentState) {}

// Assignment overload
// King& King::operator=(King const& copyPiece) {
//     // pieceName = copyPiece.pieceName;
//     // currentPos = copyPiece.currentPos;
//     // color = copyPiece.color;
//     // type = copyPiece.type;
//     // currentState = copyPiece.currentState;
//     return *this;
// }
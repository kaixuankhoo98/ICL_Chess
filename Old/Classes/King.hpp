#ifndef KING_H
#define KING_H
#include "Piece.hpp"
#include <string>

// Forward declarations
class Position;

class King : public Piece {
    // std::string pieceName;
    // std::string currentPos;
    // int color; // 0 for white, 1 for black
    // std::string type = "King";
    // Position* currentState;

public:
    bool legalMove(Position* nextPos);

    // Construction
    King(std::string name, std::string position, Position* boardState);
    King(King const& copyPiece);
    King& operator=(King const& copyPiece);
};

#endif
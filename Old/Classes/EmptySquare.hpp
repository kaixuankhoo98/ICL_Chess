#ifndef EMPTY_H
#define EMPTY_H
#include "Piece.hpp"
#include <string>

// Forward declarations
class Position;

class EmptySquare : public Piece {

public:
    EmptySquare(std::string position, Position* boardState);

    bool legalMove(Position* nextPos);
};

#endif
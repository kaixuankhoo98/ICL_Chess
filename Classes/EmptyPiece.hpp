#ifndef EMPTY_H
#define EMPTY_H
#include "Piece.hpp"

class EmptyPiece : public Piece {

public:
    // Constructor
    EmptyPiece(std::string position); // using base class constructor

    // Override
    bool legalMove(std::string newPosition); // always false for empty piece!
};

#endif
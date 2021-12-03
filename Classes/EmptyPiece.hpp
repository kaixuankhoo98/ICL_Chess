#ifndef EMPTY_H
#define EMPTY_H
#include "Piece.hpp"

class EmptyPiece : public Piece {

public:
    EmptyPiece(std::string position); // using base class constructor 
};

#endif
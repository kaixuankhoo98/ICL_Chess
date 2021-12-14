#ifndef PAWN_H
#define PAWN_H
#include "Piece.hpp"

class Pawn : public Piece {

public:
    Pawn(std::string position, int color); // using base class constructor 
    Pawn* clone();
    ~Pawn() override {};

    // Functions
    bool legalMove(std::string newPosition);
    bool legalCapture(std::string newPosition);
};

#endif
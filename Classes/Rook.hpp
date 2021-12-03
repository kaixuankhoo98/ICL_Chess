#ifndef ROOK_H
#define ROOK_H
#include "Piece.hpp"

class Rook : public Piece {

public:
    Rook(std::string position, int color); // using base class constructor 
    
    // Functions
    bool legalMove(std::string newPosition);
};

#endif
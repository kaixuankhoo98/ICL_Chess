#ifndef ROOK_H
#define ROOK_H
#include "Piece.hpp"

class Rook : public Piece {

public:
    // Construction
    Rook(std::string position, int color); // using base class constructor 
    ~Rook() override {};
    
    // Functions
    bool legalMove(std::string newPosition);
    bool legalCapture(std::string newPosition);
};

#endif
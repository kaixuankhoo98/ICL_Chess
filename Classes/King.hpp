#ifndef KING_H
#define KING_H
#include "Piece.hpp"

class King : public Piece {

public:
    King(std::string position, int color); // using base class constructor 
    King* clone();
    ~King() override {};

    // Functions
    bool legalMove(std::string newPosition);
    bool legalCapture(std::string newPosition);
};

#endif
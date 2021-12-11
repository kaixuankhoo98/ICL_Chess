#ifndef KNIGHT_H
#define KNIGHT_H
#include "Piece.hpp"

class Knight : public Piece {

public:
    Knight(std::string position, int color); // using base class constructor 
    ~Knight() override {};

    // Functions
    std::string getLongName();
    bool legalMove(std::string newPosition);
    bool legalCapture(std::string newPosition);
};

#endif
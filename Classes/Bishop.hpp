#ifndef BISHOP_H
#define BISHOP_H
#include "Piece.hpp"

class Bishop :  public Piece {

public:
    Bishop(std::string position, int color); // using base class constructor 
    Bishop* clone();
    ~Bishop() override {};


    // Functions
    bool legalMove(std::string newPosition);
    bool legalCapture(std::string newPosition);
};

#endif
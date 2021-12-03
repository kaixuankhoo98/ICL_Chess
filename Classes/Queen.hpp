#ifndef QUEEN_H
#define QUEEN_H
#include "Piece.hpp"

class Queen : public Piece {

public:
    Queen(std::string position, int color); // using base class constructor 
    
    // Functions
    bool legalMove(std::string newPosition);
};

#endif
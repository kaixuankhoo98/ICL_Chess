#ifndef POSITION_H
#define POSITION_H

#include "Piece.hpp"
#include "../functions.hpp"
#include <string>

class Position {
    std::string board[8][8];
    Piece* boardPosition[8][8];

public:
    // Getter functions
    Piece* getBoard(int rank, int file) const; 

    // Construction-related
    Position(char const* filename);
    Position(){};
};

#endif
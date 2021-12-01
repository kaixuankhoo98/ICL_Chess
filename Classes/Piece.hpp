#ifndef PIECE_H
#define PIECE_H
#include "functions.hpp"

class Piece {

public:
    Piece(int color, int type);
};
// derived classes for each piece
// somehow keep track of is it black or white (in construction, with 0 for white and 1 for black as a parameter)

#endif
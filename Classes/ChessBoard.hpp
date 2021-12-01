#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include "functions.hpp"
#include <string>

class ChessBoard {

public:
    submitMove(std::string currentPos, std::string nextPos);
};
// derived classes for each piece
// somehow keep track of is it black or white (in construction, with 0 for white and 1 for black as a parameter)

#endif
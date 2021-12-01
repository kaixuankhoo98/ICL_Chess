#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Classes/Position.hpp"
#include "Classes/Piece.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

class ChessBoard {
    std::string currentBoard[8][8];
    int moveCounter = 0; // remember for makeMove, moveCounter++
    Position* currentState;
    Position* nextState;
    // std::string nextState[8][8];

public:
    // Create or edit the board
    // void submitMove(std::string currentPos, std::string nextPos);
    
    // Construction-related
    ChessBoard();
    ChessBoard(int i);
};
// derived classes for each piece
// somehow keep track of is it black or white (in construction, with 0 for white and 1 for black as a parameter)

#endif
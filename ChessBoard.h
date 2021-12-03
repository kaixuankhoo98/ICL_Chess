#ifndef CHESSBOARD_H
#define CHESSBOARD_H

// #include "Classes/Piece.cpp"
#include "functions.hpp"
#include <string>

// Forward declarations
class Piece;
class EmptyPiece;

class ChessBoard {
    Piece* boardState[8][8];
public: 
    ChessBoard();

    // Getter functions
    void printBoard(Piece* board[8][8]);
    // Piece* getPiece();
};

#endif
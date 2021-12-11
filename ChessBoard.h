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
    Piece* nextBoard[8][8];
    int moveCounter = 0;
public: 
    ChessBoard();

    // ====== Getter functions =====
    void printBoard(Piece* board[8][8]);
    std::string getKingPos(int color); // returns string of king's position
    Piece* getPiece(std::string position); 
    void coutMove(std::string origin, std::string destination);

    // ====== Setter functions ======
    void movePiece(std::string origin, std::string destination, int number); // number=0 for moving to empty, n=1 for capturing.
    int writeNextBoard(std::string origin, std::string destination); // similar to git add :D
    // writeNextBoard may have to be a bool, so that I can return if there is a piece in the way.
    void pushNextBoard(); // similar to git push :D
    void submitMove(std::string origin, std::string destination); // as determined by spec
    void resetBoard();
    // Piece* getPiece();
};

#endif
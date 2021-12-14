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
    //Piece* moveChecker[8][8];
    int moveCounter = 0;
    bool gameOver = false;
public: 
    ChessBoard();

    // ====== Getter functions =====
    void printBoard(Piece* board[8][8]);
    std::string getKingPos(int color); // returns string of king's position
    Piece* getPiece(std::string position, Piece* board[8][8]); 
    void coutMove(std::string origin, std::string destination);

    // ========== Checkers ==========
    bool notBlocked(std::string origin, std::string destination);
    bool probeRook(int oldRank, int newRank, int oldFile, int newFile); // probes to see if that piece is blocked
    bool probeBishop(int oldRank, int newRank, int oldFile, int newFile); // probes to see if that piece is blocked
    bool kingInCheck(int color, Piece* board[8][8]); // checks if the move results in a self-check
    bool noMovesForColor(int color);

    // ====== Setter functions ======
    void suggestMove(int originRank, int originFile, int destinationRank, int destinationFile); // writes a move to next board
    void movePiece(std::string origin, std::string destination, int number); // number=0 for moving to empty, n=1 for capturing.
    int writeNextBoard(std::string origin, std::string destination); // similar to git add :D
    int writeNextBoardForNoMoves(std::string origin, std::string destination);
    // writeNextBoard may have to be a bool, so that I can return if there is a piece in the way.
    void pushNextBoard(); // similar to git push :D
    void submitMove(std::string origin, std::string destination); // as determined by spec
    void resetBoard();
    void cleanNextBoard(); // sets next to current
    
    // Piece* getPiece();
};

#endif
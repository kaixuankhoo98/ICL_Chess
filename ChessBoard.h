#ifndef CHESSBOARD_H
#define CHESSBOARD_H

// #include "Classes/Piece.cpp"
#include "functions.hpp"
#include <string>
#include <vector>

// Forward declarations
class Piece;
class EmptyPiece;

class ChessBoard {
    Piece* boardState[8][8];
    Piece* nextBoard[8][8];

    std::vector<std::string> whiteGraveyard;
    std::vector<std::string> blackGraveyard;
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
    void pushNextBoard(std::string destination); // similar to git push :D
    void submitMove(std::string origin, std::string destination); // as determined by spec
    void resetBoard();
    void cleanNextBoard(); // Creates deep copies of boardState to nextBoard.
    void deleteNextBoard();
    
    // ============ ACCESSORY FUNCTIONS ==========
    /* PrintBoard Function: something i put a lot of time into!
        So the printBoard function is something I implemented for readability on my part, so I could visualize the board. 
        Example output includes:
                  +=======================+
                8 ‖bR|bN|bB|bQ|bK|bB|bN|bR‖
                7 ‖bP|bP|bP|bP|bP|bP|bP|bP‖             White Graveyard
                6 ‖..|..|..|..|..|..|..|..‖
                5 ‖..|..|..|..|..|..|..|..‖
                4 ‖..|..|..|..|..|..|..|..‖
                3 ‖..|..|..|..|..|..|..|..‖             Black Graveyard
                2 ‖wP|wP|wP|wP|wP|wP|wP|wP‖
                1 ‖wR|wN|wB|wQ|wK|wB|wN|wR‖
                  +=======================+
                   A  B  C  D  E  F  G  H 
        
        And a graveyard (e.g. final position of the spec moves):
                White's Bishop moves from D3 to G6
                  +=======================+
                8 ‖bR|..|bB|bQ|bK|..|..|bR‖
                7 ‖bP|..|bP|bN|..|..|bP|..‖             White Graveyard
                6 ‖..|bP|..|..|bP|bN|wB|bP‖             wN wP wQ 
                5 ‖..|..|..|..|..|..|..|..‖
                4 ‖..|..|..|wP|..|..|..|..‖
                3 ‖wB|..|wP|..|..|..|..|..‖             Black Graveyard
                2 ‖wP|..|wP|..|..|wP|wP|wP‖             bB bP bP 
                1 ‖wR|..|..|..|wK|..|wN|wR‖
                  +=======================+
                   A  B  C  D  E  F  G  H  

                Checkmate! 
         */
    // Here I have the playGame function that allows 2 users to take turns inserting moves!
    void playGame();
};

#endif
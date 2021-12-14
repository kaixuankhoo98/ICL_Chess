#include "ChessBoard.h"
#include "Classes/Piece.hpp"
#include "Classes/EmptyPiece.hpp"
#include "Classes/King.hpp"
#include "Classes/Pawn.hpp"
#include "Classes/Rook.hpp"
#include "Classes/Bishop.hpp"
#include "Classes/Knight.hpp"
#include "Classes/Queen.hpp"
#include <iostream>
#include <unistd.h>
using namespace std;

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ======================== Construction ===========================
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
ChessBoard::ChessBoard() {
    cout << "New chess game started!" << endl;

    // boardState[0][0] = new EmptyPiece("A8");
    // cout << boardState[0][0]->getColor() << endl;
    // ----------- Create a board --------------
    // Black backline
    boardState[0][0] = new Rook("A8", 1);
    boardState[0][1] = new Knight("B8", 1);
    boardState[0][2] = new Bishop("C8", 1);
    boardState[0][3] = new Queen("D8", 1);
    boardState[0][4] = new King("E8", 1);
    boardState[0][5] = new Bishop("F8", 1);
    boardState[0][6] = new Knight("G8", 1);
    boardState[0][7] = new Rook("H8", 1);
    // Pawns and empty spaces
    for (int file = 0; file < 8; file++) { // black pawns
        string position = stringPosition(file, 1);
        boardState[1][file] = new Pawn(position, 1);
    }
    for (int rank = 2; rank < 8; rank++) { // empty spaces
        for (int file = 0; file < 8; file++) {
            string position = stringPosition(file, rank);
            boardState[rank][file] = new EmptyPiece(position);
        }
    }
    for (int file = 0; file < 8; file++) { // white pawns
        string position = stringPosition(file, 6);
        boardState[6][file] = new Pawn(position, 0);
    }
    // White backline
    boardState[7][0] = new Rook("A1", 0);
    boardState[7][1] = new Knight("B1", 0);
    boardState[7][2] = new Bishop("C1", 0);
    boardState[7][3] = new Queen("D1", 0);
    boardState[7][4] = new King("E1", 0);
    boardState[7][5] = new Bishop("F1", 0);
    boardState[7][6] = new Knight("G1", 0);
    boardState[7][7] = new Rook("H1", 0);

    printBoard(boardState); // prints board
    sleep(1); // delete later
    // cout << getKingPos(0) << endl;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ====================== Getter Functions =========================
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ChessBoard::printBoard(Piece* board[8][8]) {
    cout << "  +=======================+" << endl;

    for (int rank = 0; rank < 8; rank++) {
        cout << 8-rank << " ‖";
        for (int file = 0; file < 7; file++) {
            cout << board[rank][file]->getName() << "|";
        }
        cout << board[rank][7]->getName() << "‖";
        cout << "\n";
        // cout << "------------------------\n";
    }
    cout << "  +=======================+" << endl;
    cout << "   A  B  C  D  E  F  G  H  " << endl << endl;
}
std::string ChessBoard::getKingPos(int color) {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            if (boardState[rank][file]->getName()[1] == 'K' 
            && boardState[rank][file]->getColor() == color) {
                return boardState[rank][file]->getPos();
            }
        }
    }
    return "I9";
}
Piece* ChessBoard::getPiece(std::string position, Piece* board[8][8]) {
    int rank = stringToRank(position);
    int file = stringToFile(position);
    return board[rank][file];
    // for (int rank = 0; rank < 8; rank++) {
    //     for (int file = 0; file < 8; file++) {
    //         if (boardState[rank][file] != nullptr) {
    //             if (boardState[rank][file]->getPos() == position) {
    //                 return boardState[rank][file];
    //             }
    //         }
    //     }
    // }
    // return nullptr;
}
void ChessBoard::coutMove(string origin, string destination) {
    cout << this->getPiece(origin, boardState)->getLongName() << " moves from " << origin << " to " << destination;
} 

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ====================== Checker Function =========================
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
bool ChessBoard::notBlocked(std::string origin, std::string destination) {
    Piece* originPiece = getPiece(origin, boardState);
    string name = originPiece->getName();
    // Piece* destinationPiece = getPiece(destination);
    int newRank = stringToRank(destination);
    int newFile = stringToFile(destination);
    int oldRank = stringToRank(origin);
    int oldFile = stringToFile(origin);
    
    if (origin == destination) {
        return false;
    }
    // ========== Pawns not moving 2 steps if blocked ===========
    // if (name[1] == 'P') {
    //     if (originPiece->getColor() == 0) { // white pawn
    //         if (boardState[oldRank-1][oldFile]->getName() != "..") 
    //             return false;
    //     }
    //     if (originPiece->getColor() == 1) { // white pawn
    //         if (boardState[oldRank+1][oldFile]->getName() != "..")
    //             return false;
    //     }
    // }
    // ========== Rooks being blocked ===========
    if (name[1] == 'R') {
        if (probeRook(oldRank, newRank, oldFile, newFile) == false) { 
            // !probeRook can be used, but i chose this for readability
            return false;
        }
    }
    // ========= Bishops being blocked ==========
    if (name[1] == 'B') {
        if (probeBishop(oldRank, newRank, oldFile, newFile) == false) {
            return false;
        }
    }
    // ========== Queens being blocked ==========
    if (name[1] == 'Q') { // behaves like a rook + bishop
        if ((newRank==oldRank) || newFile == oldFile) { // moving like a rook
            if (probeRook(oldRank, newRank, oldFile, newFile) == false) { 
                // !probeRook can be used, but i chose this for readability
                return false;
            }
        } else { // moving like a bishop
            if (probeBishop(oldRank, newRank, oldFile, newFile) == false) {
                return false;
            }
        }
    }

    return true;
}
bool ChessBoard::probeRook(int oldRank, int newRank, int oldFile, int newFile) {
    if (oldRank == newRank) { // check when moving along a same rank
        int fileIncrement = (newFile>oldFile)? 1 : -1; // increment depends on which is larger
        for (int checkFile = oldFile+fileIncrement; checkFile != newFile; checkFile = checkFile+fileIncrement) {
            // cout << oldRank << " " << checkFile << endl;
            if (boardState[oldRank][checkFile]->getName() != "..") {
                return false;
            }
        }
    }
    if (oldFile == newFile) { // check when moving along a same file
        int rankIncrement = (newRank>oldRank)?  1 : -1; // increment depends on which is larger
        for (int checkRank = oldRank+rankIncrement; checkRank != newRank; checkRank = checkRank+rankIncrement) {
            if (boardState[checkRank][oldFile]->getName() != "..") {
                return false;
            }
        }
    }
    return true;
}
bool ChessBoard::probeBishop(int oldRank, int newRank, int oldFile, int newFile) {
    int fileIncrement = (newFile>oldFile)? 1 : -1;
    int rankIncrement = (newRank>oldRank)?  1 : -1;
    int checkFile;
    int checkRank;

    for (checkFile = oldFile+fileIncrement, checkRank = oldRank + rankIncrement; // increment the file and rank together
        checkFile != newFile && checkRank !=newRank; // until reaching the last one
        checkFile = checkFile+fileIncrement, checkRank = checkRank+rankIncrement) {

        // cout << checkRank << " " << checkFile << endl;
        if (boardState[checkRank][checkFile]->getName() != "..") {
            return false;
        }
    }
    return true;
}
bool ChessBoard::kingInCheck(int color, Piece* board[8][8]) {
    int oppositeColor = (color+1) % 2;
    string kingPos = getKingPos(color);

    // cout << "Checking " << kingPos << endl;
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            if(board[rank][file]->getColor() == oppositeColor) { // only need to check opponent's pieces
                if(board[rank][file]->legalCapture(kingPos) ) {// see if they legally move to king's position
                    // and are not blocked by other pieces
                    if (notBlocked(board[rank][file]->getPos(), kingPos) == true)
                        return true;
                }
            }
        }
    }

    return false;
}
bool ChessBoard::noMovesForColor(int color) {
    // Copy old board
    cleanNextBoard();
    // string kingPos = getKingPos(color);
    // Go through every piece
    // Write to next board every move
    // See if its own king is in check
        // if king is not in check, set flag to false
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            // for every piece 
            if (nextBoard[rank][file]->getColor() == (color)%2) { 
                // only check this color
                for (int toRank = 0; toRank < 8; toRank++) {
                    for (int toFile = 0; toFile < 8; toFile++) {
                        // !!!! HERE !!!!
                        Piece* temp = nextBoard[toRank][toFile];
                        if (writeNextBoardForNoMoves(stringPosition(file, rank), stringPosition(toFile, toRank)) == 0) {
                            cleanNextBoard();
                            return false;
                        } else {
                            cleanNextBoard();
                        }
                    }
                }
            }
        }
    }
    return true;
}

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ====================== Setter Functions =========================
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ChessBoard::suggestMove(int originRank, int originFile, int destinationRank, int destinationFile) {
    // make destination point to the old piece
    delete nextBoard[destinationRank][destinationFile];
    nextBoard[destinationRank][destinationFile] = nextBoard[originRank][originFile]; // point to same object
    nextBoard[destinationRank][destinationFile]->setPos(stringPosition(destinationFile, destinationRank)); // update the piece's position member
    // replace old position with new empty piece
    nextBoard[originRank][originFile] = new EmptyPiece(stringPosition(originFile, originRank));
}
void ChessBoard::movePiece(string origin, string destination, int number) {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            nextBoard[rank][file] = boardState[rank][file];
        }
    }

    int const originRank = stringToRank(origin);
    int const originFile = stringToFile(origin);
    int const destinationRank = stringToRank(destination);
    int const destinationFile = stringToFile(destination);
    
    // ========== Moving to empty position ==========
    if (number == 0) {
        if (nextBoard[originRank][originFile]->legalMove(destination)) {
            suggestMove(originRank, originFile, destinationRank, destinationFile);
        }
    }
    // ============= Capturing a piece =============
    if (number == 1) {
        if (nextBoard[originRank][originFile]->legalCapture(destination)) {
            suggestMove(originRank, originFile, destinationRank, destinationFile);
        }
    }
}
int ChessBoard::writeNextBoard(string origin, string destination) {
    Piece* originPiece = getPiece(origin, boardState);
    Piece* destinationPiece = getPiece(destination, boardState);
    string turn;
    if (originPiece->getColor() == 0)
        turn = "White";
    if (originPiece->getColor() == 1)
        turn = "Black";
    
    // No piece in origin
    if (originPiece->getName() == "..") {
        return 5;
    }
    // Check if it is correct turn
    if (moveCounter % 2 != originPiece->getColor()) {
        return 4;
    }
    // =========== Moving to empty space =============
    if (destinationPiece->getName() == "..") { 
        if (originPiece->legalMove(destination) == false) { // if not a legal move for the piece
            return 1; // Cannot move there
        } else {
            if (notBlocked(origin, destination) == false) {
                return 1;
            }
        }
        // Check if piece is being blocked
        
        movePiece(origin, destination, 0); // 0 is for moving to empty space
        // Make sure king isn't in check after
        if (kingInCheck((moveCounter+2)%2, nextBoard) == true) { // +2 mod 2 in case its 0
            cout << "Uhh hello? " << turn << " is in check!" << endl;
            return 1; 
        }

        coutMove(origin, destination); cout << endl;
        return 0;
    } else {
        // =============== For capturing =================
        if (originPiece->getColor() != destinationPiece->getColor()) { // if not same color, proceed
            if (originPiece->legalCapture(destination) == false) { // if not a legal capture move for the piece
                return 1; // Cannot move there
            } else {
                if (notBlocked(origin, destination) == false) {
                    return 1;
                }
            }
            string pieceCaptured = destinationPiece->getLongName();
            movePiece(origin, destination, 1); // 1 is for capturing a piece
            // King in check
            if (kingInCheck((moveCounter+2)%2, nextBoard) == true) { // +2 mod 2 in case its 0
                cout << "Uhh hello? " << turn << " is in check!" << endl;
                return 1; 
            }
            coutMove(origin, destination);
            cout << " taking " << pieceCaptured << endl;
            return 0;
        } else {
            return 1; // Cannot move there.
        }
    }
} 
int ChessBoard::writeNextBoardForNoMoves(string origin, string destination) {
    Piece* originPiece = getPiece(origin, boardState);
    Piece* destinationPiece = getPiece(destination, boardState);
    // =========== Moving to empty space =============
    if (destinationPiece->getName() == "..") { 
        if (originPiece->legalMove(destination) == false) { // if not a legal move for the piece
            return 1; // Cannot move there
        } else {
            if (notBlocked(origin, destination) == false) {
                return 1;
            }
        }
        movePiece(origin, destination, 0); // 0 is for moving to empty space
        if (kingInCheck((moveCounter+2)%2, nextBoard) == true) { // +2 mod 2 in case its 0
            // movePiece(origin, destination, 0);
            // if (kingInCheck((moveCounter+2)%2, nextBoard) == true) {
            //     return 1;
            // }
            // return 1;
        }
        return 0;
    } else {
        // =============== For capturing =================
        if (originPiece->getColor() != destinationPiece->getColor()) { // if not same color, proceed
            if (originPiece->legalCapture(destination) == false) { // if not a legal capture move for the piece
                return 1; // Cannot move there
            } else {
                if (notBlocked(origin, destination) == false) {
                    return 1;
                }
            }
            movePiece(origin, destination, 1); // 1 is for capturing a piece
            if (kingInCheck((moveCounter+2)%2, nextBoard) == true) { // +2 mod 2 in case its 0
                // return 1; // ????? 
            }
            return 0;
        } else {
            return 1; // Cannot move there.
        }
    }
} 

void ChessBoard::pushNextBoard() {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            boardState[rank][file] = nextBoard[rank][file];
        }
    }
    moveCounter++; 
    // cout << "Move counter: " << moveCounter << endl;
}
void ChessBoard::submitMove(std::string origin, std::string destination) {
    // cout << boardState[0][4]->getName() << endl;
    // Is game still running?
    if (gameOver) {
        cout << "The game has ended. Please reset the board. " << endl;
        return;
    }
    
    Piece* originPiece = getPiece(origin, boardState);
    int writeReturnCode = writeNextBoard(origin, destination);
    string turn;
    if (originPiece->getColor() == 0)
        turn = "White";
    if (originPiece->getColor() == 1)
        turn = "Black";
    // int turnCounter = moveCounter % 2;
    
    // ===== Sorting the right output depending on the parameters given. =====
    if (writeReturnCode == 5) { // empty origin
        cout << "There is no piece at position " << origin << "!" << endl;
        return;
    }
    if (writeReturnCode == 4) { // incorrect turn
        cout << "It is not " << turn << "'s turn to move!" << endl;
        return;
    }
    if (origin == destination) {
        cout << "Don't be silly. " << originPiece->getLongName() << " is already there." << endl;
        return;
    }
    if (writeReturnCode == 1) { // Cannot move
        cout << originPiece->getLongName() << " cannot move to " << destination  << "!" << endl;
        return;
    }
    
    // ========== Error for putting your own king in check ==============
    if (writeReturnCode == 0) {
        if (kingInCheck((moveCounter+2)%2, nextBoard) == true) { // +2 mod 2 in case its 0
            cout << turn << " cannot put their own King in check!" << endl;
            return;
        } else {
            pushNextBoard(); // submit the nextBoard to the boardState. this is where moveCounter++
            printBoard(boardState); 
        }
    }
    
    // If you're putting opponent in check after your move
    if (kingInCheck((moveCounter+2)%2, boardState) == true) { // +2 mod 2 in case its 0
        string oppturn;
        if (originPiece->getColor() == 1)
            oppturn = "White";
        if (originPiece->getColor() == 0)
            oppturn = "Black";
        cout << oppturn << " is in check" << endl;
    }
    if (noMovesForColor((moveCounter+2)%2) == true) {
        // Checkmate
        cout << "Checkmate! " << endl;
        // Stalemate
    }
    
    // coutMove(origin, destination); cout << endl;
    sleep(1); // delete later
}
void ChessBoard::resetBoard() {
    // clear data
    for (int rank = 0; rank < 8; rank++) { 
        for (int file = 0; file < 8; file++) {
            string position = stringPosition(file, rank);
            delete boardState[rank][file];
        }
    }
    // reassign fresh board
    cout << "New chess game started!" << endl;

    // boardState[0][0] = new EmptyPiece("A8");
    // cout << boardState[0][0]->getColor() << endl;
    // ----------- Create a board --------------
    // Black backline
    boardState[0][0] = new Rook("A8", 1);
    boardState[0][1] = new Knight("B8", 1);
    boardState[0][2] = new Bishop("C8", 1);
    boardState[0][3] = new Queen("D8", 1);
    boardState[0][4] = new King("E8", 1);
    boardState[0][5] = new Bishop("F8", 1);
    boardState[0][6] = new Knight("G8", 1);
    boardState[0][7] = new Rook("H8", 1);
    // Pawns and empty spaces
    for (int file = 0; file < 8; file++) { // black pawns
        string position = stringPosition(file, 1);
        boardState[1][file] = new Pawn(position, 1);
    }
    for (int rank = 2; rank < 8; rank++) { // empty spaces
        for (int file = 0; file < 8; file++) {
            string position = stringPosition(file, rank);
            boardState[rank][file] = new EmptyPiece(position);
        }
    }
    for (int file = 0; file < 8; file++) { // white pawns
        string position = stringPosition(file, 6);
        boardState[6][file] = new Pawn(position, 0);
    }
    // White backline
    boardState[7][0] = new Rook("A1", 0);
    boardState[7][1] = new Knight("B1", 0);
    boardState[7][2] = new Bishop("C1", 0);
    boardState[7][3] = new Queen("D1", 0);
    boardState[7][4] = new King("E1", 0);
    boardState[7][5] = new Bishop("F1", 0);
    boardState[7][6] = new Knight("G1", 0);
    boardState[7][7] = new Rook("H1", 0);

    printBoard(boardState); // prints board
    sleep(1); // delete later
    moveCounter = 0;
}
void ChessBoard::cleanNextBoard() {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            nextBoard[rank][file] = boardState[rank][file];
        }
    }
}
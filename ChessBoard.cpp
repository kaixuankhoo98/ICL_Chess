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
Piece* ChessBoard::getPiece(std::string position) {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            if (boardState[rank][file] != nullptr) {
                if (boardState[rank][file]->getPos() == position) {
                    return boardState[rank][file];
                }
            }
        }
    }
    return nullptr;
}
void ChessBoard::coutMove(string origin, string destination) {
    cout << this->getPiece(destination)->getLongName() << " moves from " << origin << " to " << destination;
} // wtf is going on here lol

// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ====================== Setter Functions =========================
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void ChessBoard::movePiece(string origin, string destination, int number) {
    // Copy old board
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
            // make destination point to the old piece
            delete nextBoard[destinationRank][destinationFile];
            nextBoard[destinationRank][destinationFile] = nextBoard[originRank][originFile]; // point to same object
            nextBoard[destinationRank][destinationFile]->setPos(destination); // update the piece's position member
            // replace old position with new empty piece
            nextBoard[originRank][originFile] = new EmptyPiece(origin);
        }
    }
    // ============= Capturing a piece =============
    if (number == 1) {
        if (nextBoard[originRank][originFile]->legalCapture(destination)) {
            // make destination point to the old piece
            delete nextBoard[destinationRank][destinationFile];
            nextBoard[destinationRank][destinationFile] = nextBoard[originRank][originFile]; // point to same object
            nextBoard[destinationRank][destinationFile]->setPos(destination); // update the piece's position member
            // replace old position with new empty piece
            nextBoard[originRank][originFile] = new EmptyPiece(origin);
        }
    }
}
int ChessBoard::writeNextBoard(string origin, string destination) {
    Piece* originPiece = getPiece(origin);
    Piece* destinationPiece = getPiece(destination);
    
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
        }
        // Check if piece is being blocked
        movePiece(origin, destination, 0); // 0 is for moving to empty space
        coutMove(origin, destination); cout << endl;
        return 0;
    }
    // =============== For capturing =================
    if (originPiece->getColor() != destinationPiece->getColor()) { // if not same color, proceed
        if (originPiece->legalCapture(destination) == false) { // if not a legal capture move for the piece
            return 1; // Cannot move there
        }
        string pieceCaptured = destinationPiece->getLongName();
        // Check if piece is being blocked
        movePiece(origin, destination, 1); // 1 is for capturing a piece
        coutMove(origin, destination);
        cout << " taking " << pieceCaptured << endl;
        return 0;
    } else {
        return 1; // Cannot move there.
    }
} 
void ChessBoard::pushNextBoard() {
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            boardState[rank][file] = nextBoard[rank][file];
        }
    }
    moveCounter++; 
    cout << "Move counter: " << moveCounter << endl;
}
void ChessBoard::submitMove(std::string origin, std::string destination) {
    Piece* originPiece = getPiece(origin);
    int writeReturnCode = writeNextBoard(origin, destination);
    string turn;
        if (originPiece->getColor() == 0)
            turn = "White";
        if (originPiece->getColor() == 1)
            turn = "Black";
    
    // ===== Sorting the right output depending on the parameters given. =====
    if (writeReturnCode == 5) { // empty origin
        cout << "There is no piece at position " << origin << "!" << endl;
    }
    if (writeReturnCode == 4) { // incorrect turn
        cout << "It is not " << turn << "'s turn to move!" << endl;
    }
    if (writeReturnCode == 1) { // Cannot move
        cout << originPiece->getLongName() << " cannot move to " << destination << endl;
    }
    // If nextBoard has the mover's king in check 
        // ... cout << turn << " cannot put their own King in check!" << endl;
    if (writeReturnCode == 0) {
        pushNextBoard(); // submit the nextBoard to the boardState
        printBoard(boardState); 
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
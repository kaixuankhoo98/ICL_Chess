#include "ChessBoard.h"
#include "Classes/Piece.hpp"
#include "Classes/EmptyPiece.hpp"
#include "Classes/King.hpp"
#include <iostream>
using namespace std;

ChessBoard::ChessBoard() {
    cout << "New chess game started!" << endl;

    // boardState[0][0] = new EmptyPiece("A8");
    // cout << boardState[0][0]->getColor() << endl;
    // ----------- Create a board --------------
    for (int rank = 0; rank < 2; rank++) { // black kings !
        for (int file = 0; file < 8; file++) {
            string position = stringPosition(file, rank);
            boardState[rank][file] = new King(position, 1);
        }
    }
    for (int rank = 2; rank < 8; rank++) { // empty spaces
        for (int file = 0; file < 8; file++) {
            string position = stringPosition(file, rank);
            boardState[rank][file] = new EmptyPiece(position);
        }
    }
    for (int rank = 6; rank < 8; rank++) { // white kings !
        for (int file = 0; file < 8; file++) {
            string position = stringPosition(file, rank);
            boardState[rank][file] = new King(position, 0);
        }
    }

    printBoard(boardState); // prints board
}

// =============== Getter functions ===============
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
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
using namespace std;

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
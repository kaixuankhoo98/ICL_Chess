#include "Position.hpp"
#include <iostream>
#include <string>
using namespace std;

// Getter functions
Piece* Position::getBoard(int rank, int file) const {
    return boardPosition[rank][file];
}

// Construction from a base file
Position::Position(char const* filename) {
    createBoard(filename, board);
    
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            if (board[rank][file] != "..") {
                string position = stringPosition(file, rank);
                boardPosition[rank][file] = new Piece(board[rank][file], position);
            // cout << boardPosition[rank][file]->currentPos << endl;
            } else {
                boardPosition[rank][file] = nullptr;
            }
        }
    }
}


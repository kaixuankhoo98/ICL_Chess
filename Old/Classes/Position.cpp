#include "Position.hpp"
#include <iostream>
#include <string>

#define POSITION_OCCUPIED 1
#define CAPTURING_EMPTY_SQUARE 2
#define CAPTURING_OWN_PIECE 3

using namespace std;

// Getter functions
Piece* Position::getBoard(int rank, int file) const {
    return boardPosition[rank][file];
}

// Construction from a base file
Position::Position(char const* filename) {
    // createBoard(filename, board);
    
    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            string position = stringPosition(file, rank);
            boardPosition[rank][file] = new Piece("A1", position, this);
            // boardPosition[rank][file] = new EmptySquare(position, this);
            // boardPosition[rank][file] = new EmptySquare("A1", this);
            // cout << boardPosition[rank][file]->getPos() << endl;
        }
    }
}

// ======================= Functions =============================
// void Position::createPiece(string name, string position) {
//     boardPosition[stringToRank(position)][stringToFile(position)] = new Piece(name, position, this); 
//     board[stringToRank(position)][stringToFile(position)] = name;
// }
// void Position::deletePiece(string position) {
//     boardPosition[stringToRank(position)][stringToFile(position)] = nullptr; 
//     // memory leak? call delete AND deconstructor
//     board[stringToRank(position)][stringToFile(position)] = "..";
// }
// void Position::movePiece(Piece* origin, string destination) {
//     if (boardPosition[stringToRank(destination)][stringToFile(destination)] != nullptr) {
//         cerr << "Cannot move piece (" << origin->getPos() 
//         << ") into a non-empty square (" << destination << ")! Use the capture function. " << endl;
//         exit(POSITION_OCCUPIED);
//     }
//     createPiece(origin->getName(), destination);
//     deletePiece(origin->getPos()); 
// }
// void Position::capturePiece(Piece* origin, Piece* destination) {
//     if (destination == nullptr) {
//         cerr << "There is no piece to capture there." << endl;
//         exit(CAPTURING_EMPTY_SQUARE);
//     }
//     if (boardPosition[stringToRank(destination->getPos())][stringToFile(destination->getPos())]->getColor() == origin->getColor()) {
//         cerr << "You cannot capture your own piece (" << destination->getPos() << ") with the piece " << origin->getPos() << endl;
//         exit(CAPTURING_OWN_PIECE);
//     }
    
//     board[stringToRank(destination->getPos())][stringToFile(destination->getPos())] = origin->getName();
//     board[stringToRank(origin->getPos())][stringToFile(origin->getPos())] = "..";
    
    
//     // destination = origin;
//     for (int i = 0; i < 8; i++) {
//         for (int j = 0; j < 8; j++) {
//             if (boardPosition[i][j] != nullptr) {
//                 if (boardPosition[i][j]->getPos() == destination->getPos()) {
//                     boardPosition[i][j] = origin;
//                 }
//             }
//         }
//     }
//     // delete destination;
// }
#include "Queen.hpp"
#include "../functions.hpp"
#include <iostream>
using namespace std;

// ================ Construction ==============
Queen::Queen(string position, int color) : Piece(position, color) {
    if (color == 0) {
        setName("wQ");
        setLongName("White's Queen");
    }
    if (color == 1) {
        setName("bQ");
        setLongName("Black's Queen");
    }
}

bool Queen::legalMove(std::string newPosition) {
    int newRank = stringToRank(newPosition);
    int newFile = stringToFile(newPosition);
    int oldRank = stringToRank(this->getPos());
    int oldFile = stringToFile(this->getPos());

    // Rook-like behavior
    if (newRank == oldRank || newFile == oldFile) {
        return true;
    } else {
        // Bishop-like behavior
        int diffRank = newRank - oldRank; // difference between ranks
        int diffFile = newFile - oldFile; // difference between files
        if (abs(diffRank) == abs(diffFile)) {
            return true;
        }
    }

    return false;
}

bool Queen::legalCapture(std::string newPosition) {
    return legalMove(newPosition);
}
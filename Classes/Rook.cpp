#include "Rook.hpp"
#include "../functions.hpp"
#include <iostream>
using namespace std;

// ================ Construction ==============
Rook::Rook(string position, int color) : Piece(position, color) {
    if (color == 0) {
        setName("wR");
        setLongName("White's Rook");
    }
    if (color == 1) {
        setName("bR");
        setLongName("Black's Rook");
    }
}

bool Rook::legalMove(std::string newPosition) {
    int newRank = stringToRank(newPosition);
    int newFile = stringToFile(newPosition);
    int oldRank = stringToRank(this->getPos());
    int oldFile = stringToFile(this->getPos());

    if (newRank == oldRank) {
        return true;
    }
    if (newFile == oldFile) {
        return true;
    }

    return false;
}

bool Rook::legalCapture(std::string newPosition) {
    return legalMove(newPosition);
}
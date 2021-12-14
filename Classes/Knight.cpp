#include "Knight.hpp"
#include "../functions.hpp"
#include <iostream>
using namespace std;

// ================ Construction ==============
Knight::Knight(string position, int color) : Piece(position, color) {
    if (color == 0) {
        setName("wN");
        setLongName("White's Knight");
    }
    if (color == 1) {
        setName("bN");
        setLongName("Black's Knight");
    }
}
Knight* Knight::clone() {
    // cout << "copied knight" << endl;
    return new Knight (*this);
}

bool Knight::legalMove(std::string newPosition) {
    int newRank = stringToRank(newPosition);
    int newFile = stringToFile(newPosition);
    int oldRank = stringToRank(this->getPos());
    int oldFile = stringToFile(this->getPos());

    if (newRank == oldRank+1 || newRank == oldRank-1) {
        if (newFile == oldFile+2 || newFile == oldFile-2) {
            return true;
        }
    }
    if (newRank == oldRank+2 || newRank == oldRank-2) {
        if (newFile == oldFile+1 || newFile == oldFile-1) {
            return true;
        }
    }

    return false;
}

bool Knight::legalCapture(std::string newPosition) {
    return legalMove(newPosition);
}
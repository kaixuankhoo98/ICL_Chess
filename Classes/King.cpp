#include "King.hpp"
#include "../functions.hpp"
#include <iostream>
using namespace std;

// ================ Construction ==============
King::King(string position, int color) : Piece(position, color) {
    if (color == 0) {
        setName("wK");
        setLongName("White's King");
    }
    if (color == 1) {
        setName("bK");
        setLongName("Black's King");
    }
}
King* King::clone() {
    return new King (*this);
}

bool King::legalMove(std::string newPosition) {
    int newRank = stringToRank(newPosition);
    int newFile = stringToFile(newPosition);
    int oldRank = stringToRank(this->getPos());
    int oldFile = stringToFile(this->getPos());

    if (newRank>oldRank+1 || newRank<oldRank-1) {
        return false;
    } // if 2 or more ranks away
    if (newFile>oldFile+1 || newFile<oldFile-1) {
        return false;
    } // if 2 or more files away

    return true;
}

bool King::legalCapture(std::string newPosition) {
    return legalMove(newPosition);
}
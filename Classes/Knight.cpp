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

bool Knight::legalMove(std::string newPosition) {
    // int newRank = stringToRank(newPosition);
    // int newFile = stringToFile(newPosition);
    // int oldRank = stringToRank(this->getPos());
    // int oldFile = stringToFile(this->getPos());

    // implement rules

    return true;
}

bool Knight::legalCapture(std::string newPosition) {

    return true;
}
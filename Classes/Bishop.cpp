#include "Bishop.hpp"
#include "../functions.hpp"
#include <iostream>
using namespace std;

// ================ Construction ==============
Bishop::Bishop(string position, int color) : Piece(position, color) {
    if (color == 0) {
        setName("wB");
        setLongName("White's Bishop");
    }
    if (color == 1) {
        setName("bB");
        setLongName("Black's Bishop");
    }
}

bool Bishop::legalMove(std::string newPosition) {
    // int newRank = stringToRank(newPosition);
    // int newFile = stringToFile(newPosition);
    // int oldRank = stringToRank(this->getPos());
    // int oldFile = stringToFile(this->getPos());

    // implement rules

    return true;
}

bool Bishop::legalCapture(std::string newPosition) {

    return true;
}
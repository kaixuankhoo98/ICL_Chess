#include "Rook.hpp"
#include "../functions.hpp"
#include <iostream>
using namespace std;

// ================ Construction ==============
Rook::Rook(string position, int color) : Piece(position, color) {
    if (color == 0) setName("wR");
    if (color == 1) setName("bR");
}

bool Rook::legalMove(std::string newPosition) {
    // int newRank = stringToRank(newPosition);
    // int newFile = stringToFile(newPosition);
    // int oldRank = stringToRank(this->getPos());
    // int oldFile = stringToFile(this->getPos());

    // implement rules

    return true;
}
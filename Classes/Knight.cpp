#include "Knight.hpp"
#include "../functions.hpp"
#include <iostream>
using namespace std;

// ================ Construction ==============
Knight::Knight(string position, int color) : Piece(position, color) {
    if (color == 0) setName("wN");
    if (color == 1) setName("bN");
}

bool Knight::legalMove(std::string newPosition) {
    // int newRank = stringToRank(newPosition);
    // int newFile = stringToFile(newPosition);
    // int oldRank = stringToRank(this->getPos());
    // int oldFile = stringToFile(this->getPos());

    // implement rules

    return true;
}
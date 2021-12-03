#include "Pawn.hpp"
#include "../functions.hpp"
#include <iostream>
using namespace std;

// ================ Construction ==============
Pawn::Pawn(string position, int color) : Piece(position, color) {
    if (color == 0) setName("wP");
    if (color == 1) setName("bP");
}

bool Pawn::legalMove(std::string newPosition) {
    int newRank = stringToRank(newPosition);
    int newFile = stringToFile(newPosition);
    int oldRank = stringToRank(this->getPos());
    int oldFile = stringToFile(this->getPos());

    // implement rules

    return true;
}
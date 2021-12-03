#include "King.hpp"
#include "../functions.hpp"
#include <iostream>
using namespace std;

// ================ Construction ==============
King::King(string position, int color) : Piece(position, color) {
    if (color == 0) setName("wK");
    if (color == 1) setName("bK");
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
    if (newRank==oldRank && newFile==oldFile) {
        return false;
    } // if trying to move to the same square

    return true;
}
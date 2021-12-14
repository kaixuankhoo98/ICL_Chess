#include "Pawn.hpp"
#include "../functions.hpp"
#include <iostream>
using namespace std;

// ================ Construction ==============
Pawn::Pawn(string position, int color) : Piece(position, color) {
    if (color == 0) {
        setName("wP");
        setLongName("White's Pawn");
    }
    if (color == 1) {
        setName("bP");
        setLongName("Black's Pawn");
    }
}
Pawn* Pawn::clone() {
    return new Pawn (*this);
}

bool Pawn::legalMove(std::string newPosition) {
    if (getPos() == newPosition) {
        return false;
    }
    int newRank = stringToRank(newPosition);
    int newFile = stringToFile(newPosition);
    int oldRank = stringToRank(this->getPos());
    int oldFile = stringToFile(this->getPos());

    if (newFile != oldFile) {
        return false;
    }
    // ===== White Pawns =====
    if (getColor() == 0) {
        if (getPos()[1] == '2')  { // If it has not moved yet
            if (newRank == oldRank-2)
                return true;
        }
        if (newRank == oldRank-1) {
            return true;
        }
    }
    // ===== Black Pawns =====
    if (getColor() == 1) {
        if (getPos()[1] == '7')  { // If it has not moved yet
           if (newRank == oldRank+2)
                return true;
        }
        if (newRank == oldRank+1) {
            return true;
        }
    }
    return false;
}

bool Pawn::legalCapture(std::string newPosition) {
    int newRank = stringToRank(newPosition);
    int newFile = stringToFile(newPosition);
    int oldRank = stringToRank(this->getPos());
    int oldFile = stringToFile(this->getPos());

    if (newFile == oldFile+1 || newFile == oldFile-1) { // if not in the adjacent columns
        // ===== White Pawns =====
        if (getColor() == 0) {
            if (newRank == oldRank-1) {
                return true;
            }
        }
        // ===== Black Pawns =====
        if (getColor() == 1) {
            if (newRank == oldRank+1) {
                return true;
            }
        }
    }
    

    return false;
}
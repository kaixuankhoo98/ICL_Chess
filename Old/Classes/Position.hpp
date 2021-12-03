#ifndef POSITION_H
#define POSITION_H

#include "Piece.hpp"
#include "EmptySquare.hpp"
#include "../functions.hpp"
#include <string>

class Position {

public:
    Piece* boardPosition[8][8];
    
    // Getter functions
    Piece* getBoard(int rank, int file) const; 

    // Construction-related
    Position(char const* filename);
    Position(){};

    // Functions
    // void createPiece(std::string name, std::string position);
    // void deletePiece(std::string position);
    // void movePiece(Piece* origin, std::string destination);
    // void capturePiece(Piece* origin, Piece* destination);
};

#endif
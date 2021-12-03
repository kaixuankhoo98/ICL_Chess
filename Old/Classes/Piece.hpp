#ifndef PIECE_H
#define PIECE_H

#include <string>

// Forward declarations
class Position;

// ============== PIECE ==============
class Piece {
    std::string pieceName;
    std::string currentPos;
    int color; // 0 for white, 1 for black, 2 for empty
    Position* currentState; // needs pointer both ways not class members
    
public:
    // Getter functions
    int getColor() const;
    std::string getName() const;
    std::string getPos() const;

    // Construction-related
    Piece(std::string name, std::string position, Position* boardState);
    Piece(Piece const& copyPiece);
    Piece& operator=(Piece const& copyPiece);

    // Virtual functions
    // virtual bool legalMove(Position* nextPos) = 0;
    
};
// derived classes for each piece


#endif
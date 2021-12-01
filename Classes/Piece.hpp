#ifndef PIECE_H
#define PIECE_H

#include <string>

class Piece {
    std::string currentPos;
    std::string pieceName;
    int color; // 0 for white, 1 for black
    std::string type = "GARBARGE";
    
public:
    // Getter functions
    int getColor() const;
    std::string getName() const;
    std::string getPos() const;

    // Construction-related
    Piece(std::string name, std::string position);
    Piece(Piece const& copyPiece);
    Piece& operator=(Piece const& copyPiece);
};
// derived classes for each piece

// =============== KING =================
class King : public Piece {
private:
    std::string type = "King";

public:
    bool legalMove(std::string nextPos);

};

#endif
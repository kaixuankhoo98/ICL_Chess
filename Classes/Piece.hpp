#ifndef PIECE_H
#define PIECE_H

#include <string>

// =========== Abstract Class btw =========
class Piece {
    std::string name;
    std::string position;
    int color; 

public:
    Piece(std::string name, std::string position); // construct using name
    Piece(std::string position, int color); // name uninitialized for derived classes to edit

    // Getter functions
    std::string getName() const;
    std::string getPos() const;
    int getColor() const;

    // Setter functions
    void setName(std::string setName);
    virtual bool legalMove(std::string newPosition) = 0;
};

#endif
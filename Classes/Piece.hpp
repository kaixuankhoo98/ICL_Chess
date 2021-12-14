#ifndef PIECE_H
#define PIECE_H

#include <string>

// =========== Abstract Class btw =========
class Piece {
    std::string name;
    std::string position;
    int color; 
    std::string longName = "Base class name";

public:
    Piece(std::string name, std::string position); // construct using name
    Piece(std::string position, int color); // name uninitialized for derived classes to edit
    virtual ~Piece(){}; // virtual destructor
    virtual Piece* clone() = 0;

    // Getter functions
    std::string getName() const;
    std::string getPos() const;
    int getColor() const;
    std::string getLongName() const;

    // Setter functions
    void setName(std::string setName);
    void setPos(std::string setPosition);
    void setLongName(std::string setName);
    virtual bool legalMove(std::string newPosition) = 0; // for moving to empty space
    virtual bool legalCapture(std::string newPosition) = 0; // for capturing a piece
};

#endif
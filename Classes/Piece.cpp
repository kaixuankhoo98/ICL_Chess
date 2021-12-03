#include "Piece.hpp"
#include <iostream>
using namespace std;

#define INVALID_COLOR_IN_BOARD 1

// ========== Construction =========
// using name
Piece::Piece(string name, string position) : name(name), position(position) {
    if (name[0] == 'w') color = 0;
    if (name[0] == 'b') color = 1;
    if (name[0] == '.') color = 2;
    if (name[0] != 'w' && name[0] != 'b' && name[0] != '.') {
        cerr << "Invalid color " << endl;
        exit(INVALID_COLOR_IN_BOARD);
    }
} 
// using color (uninitialized name)
Piece::Piece(string position, int color) : position(position), color(color) {}

// ========= Getter =============
string Piece::getName() const {
    return name;
}
string Piece::getPos() const {
    return position;
}
int Piece::getColor() const {
    return color;
}

// ========= Setter =============
void Piece::setName(string setName) {
    name = setName;
}
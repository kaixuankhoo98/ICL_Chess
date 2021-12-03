#include "King.hpp"
#include <iostream>
using namespace std;

// ================ Construction ==============
King::King(string position, int color) : Piece(position, color) {
    if (color == 0) setName("wK");
    if (color == 1) setName("bK");
}
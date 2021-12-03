#include "EmptyPiece.hpp"
#include <iostream>
using namespace std;

// =========== Construction ================
EmptyPiece::EmptyPiece(string position) : Piece("..", position) {}
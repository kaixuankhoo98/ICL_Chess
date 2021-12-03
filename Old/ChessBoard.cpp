#include "ChessBoard.h"
#include "functions.hpp"

using namespace std;

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ============================== CREATE AND EDIT BOARD =================================
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Constructor
ChessBoard::ChessBoard() {
    cout << "A new chess game is started!" << endl;

    // test = new EmptySquare("A8");
    // currentState = new Position("EmptyBoard.cb");
    // currentState = new Position("EmptyBoard.cb");
    //printBoard(currentState->boardPosition);
    cout << "Hello there " << endl;
}

// Getter
Position* ChessBoard::getCurrState() const {
    return currentState;
}

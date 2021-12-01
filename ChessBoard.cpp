#include "ChessBoard.h"
#include "functions.hpp"

using namespace std;

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ============================== CREATE AND EDIT BOARD =================================
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Constructor
ChessBoard::ChessBoard() {
    cout << "A new chess game is started!" << endl;
    createBoard("StartBoard.cb", currentBoard);
    printBoard(currentBoard); // can be commented out if you don't want to display

    currentState = new Position("StartBoard.cb");
    // cout << currentState->getBoard(7,4)->getName() << endl; // should print out white king
}
ChessBoard::ChessBoard(int i) {
    cout << "A new chess game is started!" << endl;
    createBoard("TestBoard.cb", currentBoard);
    printBoard(currentBoard); // can be commented out if you don't want to display

    currentState = new Position("TestBoard.cb");
    cout << currentState->getBoard(7,4)->getName() << endl; // should print out white king
}

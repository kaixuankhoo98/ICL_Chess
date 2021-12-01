#include "functions.hpp"
#include <fstream>
#include <iostream>
using namespace std;

// Creates a board position from a file
void createBoard(char const* filename, string board[8][8]) {
    ifstream in;
    in.open(filename);

    for (int rank = 0; rank < 8; rank++) {
        for (int file = 0; file < 8; file++) {
            in >> board[rank][file];
            // cout << board[rank][file] << "‖";
        }
        // cout << "\n";
    }
    
    in.close();
}

// Prints a board on a beautiful chess board :)
void printBoard(string board[8][8]) {
    cout << "+=======================+" << endl;

    for (int rank = 0; rank < 8; rank++) {
        cout << "‖";
        for (int file = 0; file < 7; file++) {
            cout << board[rank][file] << "|";
        }
        cout << board[rank][7] << "‖";
        cout << "\n";
        // cout << "------------------------\n";
    }
    cout << "+=======================+" << endl << endl;
}

// Converts rank and file to string for position
// !!! Needs to be (file, rank), NOT (rank, file) in order to assign correctly
string stringPosition(int file, int rank) {
    string position = ".."; // initialize to 2 characters
    position[0] = static_cast<char>(file + static_cast<int>('A'));
    position[1] = static_cast<char>(7-rank + static_cast<int>('1')); // ranks are inverted
    position[2] = '\0';
    return position;
}

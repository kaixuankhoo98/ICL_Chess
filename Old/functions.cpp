#include "functions.hpp"
#include "Classes/Piece.hpp"
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
void printBoard(Piece* board[8][8]) {
    cout << "  +=======================+" << endl;

    for (int rank = 0; rank < 8; rank++) {
        cout << 8-rank << " ‖";
        for (int file = 0; file < 7; file++) {
            cout << board[rank][file]->getName() << "|";
        }
        cout << board[rank][7]->getName() << "‖";
        cout << "\n";
        // cout << "------------------------\n";
    }
    cout << "  +=======================+" << endl;
    cout << "   A  B  C  D  E  F  G  H  " << endl << endl;
}

// Converts rank and file to string for position && vice versa
// !!! Needs to be (file, rank), NOT (rank, file) in order to assign correctly
string stringPosition(int file, int rank) {
    string position = ".."; // initialize to 2 characters
    position[0] = static_cast<char>(file + static_cast<int>('A'));
    position[1] = static_cast<char>(7-rank + static_cast<int>('1')); // ranks are inverted
    position[2] = '\0';
    return position;
}
int stringToRank(std::string coord) {
    return 7-static_cast<int>(coord[1]-'1');
}
int stringToFile(std::string coord) {
    return static_cast<int>(coord[0]-'A');
}

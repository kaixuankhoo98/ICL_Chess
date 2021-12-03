#ifndef FUNCTIONS_H
#define FUNCITONS_H
#include <string>

//
class Piece;

void createBoard(char const* filename, std::string board[8][8]);
void printBoard(Piece* board[8][8]); // 

std::string stringPosition(int file, int rank);
int stringToRank(std::string coord);
int stringToFile(std::string coord);

#endif
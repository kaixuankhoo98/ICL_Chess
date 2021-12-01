#ifndef FUNCTIONS_H
#define FUNCITONS_H
#include <string>

void createBoard(char const* filename, std::string board[8][8]);
void printBoard(std::string board[8][8]);

std::string stringPosition(int file, int rank);

#endif
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <string>

std::string stringPosition(int file, int rank);
int stringToRank(std::string coord);
int stringToFile(std::string coord);
void printChessPiecesUnicode();

#endif
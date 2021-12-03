#include "functions.hpp"
#include <iostream>
using namespace std;

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
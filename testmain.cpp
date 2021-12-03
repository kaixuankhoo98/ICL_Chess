#include "functions.hpp"
#include <iostream>
#include <string>
using namespace std;

string stringPosition(int rank, int file);
int stringToRank(std::string coord);
int stringToFile(std::string coord);

int main() {
    // string position = stringPosition(0, 2);
    // cout << "hello " << position << " hi " << endl;
    // cout << static_cast<char>(5 + static_cast<int>('A')) << endl;

    cout << stringToRank("A3") << endl;
    // cout << stringToFile("B3") << endl;

    return 0;
}

string stringPosition(int file, int rank) {
    string position = "..";
    position[0] = static_cast<char>(file + static_cast<int>('A'));
    position[1] = static_cast<char>(7-rank + static_cast<int>('1'));
    position[2] = '\0';
    return position;
    
}
int stringToRank(std::string coord) {
    return 7-static_cast<int>(coord[1]-'1');
}
int stringToFile(std::string coord) {
    return static_cast<int>(coord[0]-'A');
}
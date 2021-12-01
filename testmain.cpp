#include "functions.hpp"
#include <iostream>
#include <string>
using namespace std;

string stringPosition(int rank, int file);

int main() {
    string position = stringPosition(0, 2);
    cout << "hello " << position << " hi " << endl;
    // cout << static_cast<char>(5 + static_cast<int>('A')) << endl;
    return 0;
}

string stringPosition(int file, int rank) {
    string position = "..";
    position[0] = static_cast<char>(file + static_cast<int>('A'));
    position[1] = static_cast<char>(7-rank + static_cast<int>('1'));
    position[2] = '\0';
    return position;
    
}
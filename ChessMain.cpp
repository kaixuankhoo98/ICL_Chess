#include "ChessBoard.h"
#include "functions.hpp"

#include <iostream>
#include <string> 

using namespace std;

int main() {
	ChessBoard cb;
	cb.submitMove("G1", "F3");
	cb.submitMove("B8", "C6");
	cb.submitMove("F3", "D4");
	cb.submitMove("C6", "D4");

	// cb.submitMove("E2", "E4"); 
	// cb.submitMove("D7", "D5");
	// cb.submitMove("D2", "D4");
	// cb.submitMove("G8", "F5");

	// cb.submitMove("E6", "E5");
	// cb.submitMove("D7", "D5");
	// // cb.submitMove("E1", "E3"); // illegal move but correct name called
	

	// -------------------------------------------
	// cout << "========================\n";
	// cout << "Testing the Chess Engine\n";
	// cout << "========================\n\n";

	// ChessBoard cb;
	// cout << '\n';

	// cb.submitMove("D7", "D6");
	// cout << '\n';

	// cb.submitMove("D4", "H6");
	// cout << '\n';

	// cb.submitMove("D2", "D4");
	// cout << '\n';

	// cb.submitMove("F8", "B4");
	// cout << '\n';

	// cout << "=========================\n";
	// cout << "Alekhine vs. Vasic (1931)\n";
	// cout << "=========================\n\n";

	// cb.resetBoard();
	// cout << '\n';

	// cb.submitMove("E2", "E4");
	// cb.submitMove("E7", "E6");
	// cout << '\n';

	// cb.submitMove("D2", "D4");
	// cb.submitMove("D7", "D5");
	// cout << '\n';

	// cb.submitMove("B1", "C3");
	// cb.submitMove("F8", "B4");
	// cout << '\n';

	// cb.submitMove("F1", "D3");
	// cb.submitMove("B4", "C3");
	// cout << '\n';

	// cb.submitMove("B2", "C3");
	// cb.submitMove("H7", "H6");
	// cout << '\n';

	// cb.submitMove("C1", "A3");
	// cb.submitMove("B8", "D7");
	// cout << '\n';

	// cb.submitMove("D1", "E2");
	// cb.submitMove("D5", "E4");
	// cout << '\n';

	// cb.submitMove("D3", "E4");
	// cb.submitMove("G8", "F6");
	// cout << '\n';

	// cb.submitMove("E4", "D3");
	// cb.submitMove("B7", "B6");
	// cout << '\n';

	// cb.submitMove("E2", "E6");
	// cb.submitMove("F7", "E6");
	// cout << '\n';

	// cb.submitMove("D3", "G6");
	// cout << '\n';



	return 0;
}

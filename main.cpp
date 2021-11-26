#include "logic.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	// 1. create board
	int sizeBoard = 6;
	bool** board = create_board(sizeBoard, sizeBoard);

	// 2. place ships
	int shipCount = 5;
	place_ships(board, shipCount, sizeBoard, sizeBoard);

	// print board
	for (int i = 0; i < sizeBoard; i++) {
			for (int j = 0; j < sizeBoard; j++) {
					cout << setw(3)  << board[i][j];
			}
					cout << endl;
	}
	// choose random position to check

	destroy_board(board, sizeBoard);
	// system("pause>0");
	return 0;

}
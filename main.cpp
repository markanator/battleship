#include "logic.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	// 1. create board
	int sizeBoard = 6;
	int shipCount = 5;

	// 1. create board
	bool** board = create_board(sizeBoard, sizeBoard);

	// 2. place ships and populate board
	place_ships(board, shipCount, sizeBoard, sizeBoard);

	// print board
	for (int i = 0; i < sizeBoard; i++) {
			for (int j = 0; j < sizeBoard; j++) {
					cout << setw(3)  << board[i][j];
			}
					cout << endl;
	}
	// 3. play game

	Coordinates* coord = find_ships(board, sizeBoard, sizeBoard, shipCount);
	cout << "x:" << coord->x << ", y:" << coord->y << endl;

	delete coord;
	coord = NULL;
	destroy_board(board, sizeBoard);
	// system("pause>0");
	return 0;

}
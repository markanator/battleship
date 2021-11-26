#include "logic.h"
#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

bool** create_board(const int height, const int width) {
    bool** board = (bool**)malloc(sizeof(bool*) * height);
    for (int i = 0; i < height; i++) {
        board[i] = (bool*)malloc(sizeof(bool) * width);
    }
    return board;
}

void destroy_board(bool** board, const int height) {
    for (int i = 0; i < height; ++i) {
        free(board[i]);
    }
    free(board);
}

void place_ships(bool** board, const int shipcount, const int width,
    const int height) {
    // TODO implement this function
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            board[i][j] = false;
        }
    }

    int count = shipcount + 1;
    while (count) {
        int h = (rand() % height);
        int w = (rand() % width);
        board[h][w] = true;
        count--;
    }
}

Coordinates* find_ships(bool** board, const int width, const int height, const int ship_count) {
    struct Coordinates* ship = new Coordinates;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (board[i][j]) {
                ship->x = i;
                ship->y = j;
                return ship;
                break;
            }
        }
    }
    return ship;

    // while (isPlaying) {
	// 	// choose random position to check
	// 	if (shipsBombed == ship_count) { isPlaying = false; }
	// 	int row = (rand() % height);
	// 	int col = (rand() % width);

    //     ResponseType res = guess(board, row, col);

    //     switch (res)
    //     {
    //     case ResponseType::HIT:
    //         std::cout << "SHIP HIT" << std::endl;
    //         shipsBombed++;
    //         break;
    //     case ResponseType::NEAR_MISS:
    //         std::cout << "SHIP NEAR MISS" << std::endl;
    //         break;
    //     case ResponseType::MISS:
    //         std::cout << "SHIP MISS" << std::endl;
    //         break;
    //     default:
    //         break;
    //     }
	// }
}

ResponseType guess(bool** board, const int x, const int y) {
    if (board[x][y]) {
        return ResponseType::HIT;
    } else if (board[x+1][y] || board[x-1][y] || board[x][y+1] || board[x][y-1]) {
    // TODO: better reach prediction
        return ResponseType::NEAR_MISS;
    }
    else {
        return ResponseType::MISS;
    }
}
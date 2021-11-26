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

void find_ships(bool** board, const int width, const int height) {
    // TODO implement
}

ResponseType guess(bool** board, const int x, const int y) {
    // TODO implement this
    return ResponseType::HIT;
}
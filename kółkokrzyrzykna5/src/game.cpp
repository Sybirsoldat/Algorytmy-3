#include "game.h"
#include <iostream>
#include <algorithm>

using namespace std;

void printBoard(const vector<vector<char>>& board) {
    int size = board.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << board[i][j];
            if (j < size - 1) cout << " | ";
        }
        cout << endl;
        if (i < size - 1) {
            for (int j = 0; j < size; j++) {
                cout << "---";
                if (j < size - 1) cout << "+";
            }
            cout << endl;
        }
    }
}

bool isMovesLeft(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == EMPTY) return true;
        }
    }
    return false;
}

int evaluate(const vector<vector<char>>& board, char player) {
    int size = board.size();

    for (int row = 0; row < size; row++) {
        if (board[row][0] != EMPTY && all_of(board[row].begin(), board[row].end(), [&](char c){ return c == board[row][0]; })) {
            return (board[row][0] == player) ? 10 : -10;
        }
    }

    for (int col = 0; col < size; col++) {
        char first = board[0][col];
        if (first != EMPTY) {
            bool win = true;
            for (int row = 1; row < size; row++) {
                if (board[row][col] != first) {
                    win = false;
                    break;
                }
            }
            if (win) return (first == player) ? 10 : -10;
        }
    }

    char firstDiagonal = board[0][0];
    if (firstDiagonal != EMPTY) {
        bool win = true;
        for (int i = 1; i < size; i++) {
            if (board[i][i] != firstDiagonal) {
                win = false;
                break;
            }
        }
        if (win) return (firstDiagonal == player) ? 10 : -10;
    }

    char secondDiagonal = board[0][size - 1];
    if (secondDiagonal != EMPTY) {
        bool win = true;
        for (int i = 1; i < size; i++) {
            if (board[i][size - 1 - i] != secondDiagonal) {
                win = false;
                break;
            }
        }
        if (win) return (secondDiagonal == player) ? 10 : -10;
    }

    return 0;
}
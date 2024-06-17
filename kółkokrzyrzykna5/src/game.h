#ifndef GAME_H
#define GAME_H

#include <vector>

using namespace std;

const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';

void printBoard(const vector<vector<char>>& board);
bool isMovesLeft(const vector<vector<char>>& board);
int evaluate(const vector<vector<char>>& board, char player);

#endif
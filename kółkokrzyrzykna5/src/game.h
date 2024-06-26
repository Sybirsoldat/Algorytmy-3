#ifndef GAME_H
#define GAME_H

#include <vector>

using namespace std;
// stałe reprezentujące graczy i puste pole
const char PLAYER_X = 'X';
const char PLAYER_O = 'O';
const char EMPTY = ' ';
// metoda wypisująca planszę
void printBoard(const vector<vector<char>>& board);
bool isMovesLeft(const vector<vector<char>>& board);
int evaluate(const vector<vector<char>>& board, char player);

#endif
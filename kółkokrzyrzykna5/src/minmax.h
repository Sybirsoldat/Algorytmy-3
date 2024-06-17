#ifndef MINIMAX_H
#define MINIMAX_H

#include <vector>

using namespace std;
// metoda oceniająca stan planszy
int minimax(vector<vector<char>>& board, int depth, bool isMax, char player, char opponent, int alpha, int beta, int maxDepth);
pair<int, int> findBestMove(vector<vector<char>>& board, char player, char opponent, int maxDepth, double& duration);

#endif
#include "minmax.h"
#include "game.h"
#include <limits>
#include <chrono>
#include <iostream>

using namespace std;
// metoda oceniająca stan planszy
int minimax(vector<vector<char>>& board, int depth, bool isMax, char player, char opponent, int alpha, int beta, int maxDepth) {
    int score = evaluate(board, player);

    // zwrócenie wyniku jeśli osiągnięto maksymalną głębokość drzewa gry
    if (score == 10) return score - depth;
    if (score == -10) return score + depth;
    if (!isMovesLeft(board)) return 0;
    // rekurencyjne wywołanie minimax
    if (depth >= maxDepth) return score;
    // algorytm minimax
    if (isMax) {
        // maksymalizacja wartości
        int best = numeric_limits<int>::min();
        // iteracja po planszy
        for (std::vector<std::vector<char>>::size_type i = 0; i < board.size(); i++) {
            for (std::vector<char>::size_type j = 0; j < board.size(); j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = player;
                    best = max(best, minimax(board, depth + 1, !isMax, player, opponent, alpha, beta, maxDepth));
                    board[i][j] = EMPTY;
                    alpha = max(alpha, best);
                    if (beta <= alpha) break;
                }
            }
        }
        return best;
    } else {
        // minimalizacja wartości
        int best = numeric_limits<int>::max();
        // iteracja po planszy
        for (std::vector<std::vector<char>>::size_type i = 0; i < board.size(); i++) {
            for (std::vector<char>::size_type j = 0; j < board.size(); j++) {
                if (board[i][j] == EMPTY) {
                    board[i][j] = opponent;
                    best = min(best, minimax(board, depth + 1, !isMax, player, opponent, alpha, beta, maxDepth));
                    board[i][j] = EMPTY;
                    beta = min(beta, best);
                    if (beta <= alpha) break;
                }
            }
        }
        return best;
    }
}
// metoda znajdująca najlepszy ruch
pair<int, int> findBestMove(vector<vector<char>>& board, char player, char opponent, int maxDepth, double& duration) {
    int bestVal = numeric_limits<int>::min();
    pair<int, int> bestMove = {-1, -1};
    // pomiar czasu
    auto start = chrono::high_resolution_clock::now();
    // iteracja po planszy
    for (std::vector<std::vector<char>>::size_type i = 0; i < board.size(); i++) {
        // iteracja po wierszach
        for (std::vector<char>::size_type j = 0; j < board.size(); j++) {
            if (board[i][j] == EMPTY) {
                board[i][j] = player;
                int moveVal = minimax(board, 0, false, player, opponent, numeric_limits<int>::min(), numeric_limits<int>::max(), maxDepth);
                board[i][j] = EMPTY;

                if (moveVal > bestVal) {
                    bestMove = {static_cast<int>(i), static_cast<int>(j)};
                    bestVal = moveVal;
                }
            }
        }
    }
    // zakończenie pomiaru czasu
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end - start;
    duration = elapsed.count();

    return bestMove;
}
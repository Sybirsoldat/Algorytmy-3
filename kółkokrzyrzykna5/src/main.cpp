#include <iostream>
#include "game.h"
#include "minmax.h"

using namespace std;

int main() {
    // rozmiar planszy i poziom trudności
    int size, maxDepth;
    cout << "Enter the size of the board (3 for 3x3, 4 for 4x4, etc.): ";
    cin >> size;
    cout << "Enter the difficulty level (1 for easy, 2 for medium, 3 for hard): ";
    cin >> maxDepth;
    maxDepth *= 2; // maksymalna głębokość drzewa gry

    // inicjalizacja planszy i graczy
    vector<vector<char>> board(size, vector<char>(size, EMPTY));
    char player = PLAYER_X, opponent = PLAYER_O;

    // wybór gracza rozpoczynającego grę
    cout << "Do you want to play first? (y/n): ";
    char choice;
    cin >> choice;
    bool playerTurn = (choice == 'y' || choice == 'Y');

    // pętla gry
    while (isMovesLeft(board) && evaluate(board, player) == 0 && evaluate(board, opponent) == 0) {
        printBoard(board);
        // ruch gracza
        if (playerTurn) {
            int row, col;
            cout << "Enter your move (row and column): ";
            cin >> row >> col;
            if (row >= 0 && row < size && col >= 0 && col < size && board[row][col] == EMPTY) {
                board[row][col] = player;
                playerTurn = false;
            } else {
                cout << "Invalid move. Try again." << endl;
            }
            // ruch komputera
        } else {
            double duration;
            pair<int, int> bestMove = findBestMove(board, opponent, player, maxDepth, duration);
            board[bestMove.first][bestMove.second] = opponent;
            cout << "Computer move time: " << duration << " seconds" << endl;
            playerTurn = true;
        }
    }

    // wyświetlenie wyniku gry
    printBoard(board);
    int finalScore = evaluate(board, player);
    if (finalScore == 10) {
        cout << "You win!" << endl;
    } else if (finalScore == -10) {
        cout << "Computer wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}
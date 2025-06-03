#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        currentPlayer = 'X';
        initializeBoard();
    }

    void initializeBoard() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                board[i][j] = ' ';
    }

    void displayBoard() {
        cout << "\n";
        cout << "  0   1   2\n";
        for (int i = 0; i < 3; ++i) {
            cout << i << " ";
            for (int j = 0; j < 3; ++j) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "  ---------\n";
        }
        cout << "\n";
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row > 2 || col < 0 || col > 2) {
            cout << "❌ Invalid move! Row and column must be between 0 and 2.\n";
            return false;
        }

        if (board[row][col] != ' ') {
            cout << "❌ That cell is already taken. Choose a different one.\n";
            return false;
        }

        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        // Rows and columns
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer &&
                 board[i][1] == currentPlayer &&
                 board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer &&
                 board[1][i] == currentPlayer &&
                 board[2][i] == currentPlayer)) {
                return true;
            }
        }

        // Diagonals
        if ((board[0][0] == currentPlayer &&
             board[1][1] == currentPlayer &&
             board[2][2] == currentPlayer) ||
            (board[0][2] == currentPlayer &&
             board[1][1] == currentPlayer &&
             board[2][0] == currentPlayer)) {
            return true;
        }

        return false;
    }

    bool isBoardFull() {
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < 3; ++j)
                if (board[i][j] == ' ')
                    return false;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    void playGame() {
        int row, col;
        cout << "🎮 Welcome to Tic-Tac-Toe (Player X vs Player O)\n";

        while (true) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (row and column between 0 and 2): ";

            while (!(cin >> row >> col)) {
                cout << "❌ Invalid input! Please enter two integers between 0 and 2.\n";
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Try again: ";
            }

            if (!makeMove(row, col)) {
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "🎉 Player " << currentPlayer << " wins!\n";
                break;
            }

            if (isBoardFull()) {
                displayBoard();
                cout << "🤝 It's a tie!\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}

#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char currentPlayer = 'X';

void printBoard() {
    cout << "\n";
    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
    cout << "---|---|---\n";
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n\n";
}

void makeMove() {
    int choice, row, col;
    while (true) {
        cout << "Player " << currentPlayer << ", enter a number (1-9): ";
        cin >> choice;

        if (choice < 1 || choice > 9) {
            cout << "Invalid choice! Try again.\n";
            continue;
        }

        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Cell already taken! Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;
        break;
    }
}

bool isBoardFull() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
    return true;
}

bool checkWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
            return true;
        if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
            return true;
    }
    if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
        return true;
    if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
        return true;
    return false;
}

int main() {
    int scoreX = 0, scoreO = 0, tie = 0;
    char playAgain = 'y';

    cout << "===== TIC TAC TOE =====\n";

    while (playAgain == 'y' || playAgain == 'Y') {
        int num = 1;
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = '0' + num++;

        currentPlayer = 'X';
        printBoard();

        while (true) {
            makeMove();
            printBoard();

            if (checkWin()) {
                cout << "Player " << currentPlayer << " wins!\n";
                if (currentPlayer == 'X') scoreX++;
                else scoreO++;
                break;
            }
            if (isBoardFull()) {
                cout << "It's a tie!\n";
                tie++;
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        cout << "Score -> X: " << scoreX << " | O: " << scoreO << " | Ties: " << tie << "\n";

        // Keep asking until valid y or n is entered
        while (true) {
            cout << "Play again? (y/n): ";
            cin >> playAgain;

            if (playAgain == 'y' || playAgain == 'Y' || playAgain == 'n' || playAgain == 'N') {
                break;
            }
            cout << "Invalid input! Please enter y or n.\n";
        }
    }

    cout << "\nThanks for playing!\n";
    return 0;
}
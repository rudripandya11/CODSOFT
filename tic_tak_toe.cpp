#include <iostream>
#include <string>

using namespace std;

const int SIZE = 3;

void printBoard(char board[SIZE][SIZE]) {
    cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "-------------" << endl;
    cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "-------------" << endl;
    cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool checkWin(char board[SIZE][SIZE], char player) {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
    }

    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

bool checkTie(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int main() {
    char board[SIZE][SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    char player1 = 'X';
    char player2 = 'O';
    bool gameOver = false;
    printBoard(board);
    
    while (!gameOver) {
        
        cout<<" "<<endl;
        cout << "Player 1(x) turn enter a number (1-9) to place your mark: ";
        int position;
        cin >> position;

        int row = (position - 1) / SIZE;
        int col = (position - 1) % SIZE;

        if (board[row][col] != ' ') {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        board[row][col] = player1;

        printBoard(board);
     

        if (checkWin(board, player1)) {
            cout << "Player 1 wins!" << endl;
            gameOver = true;
        } else if (checkTie(board)) {
            printBoard(board);
            cout << "It's a tie!" << endl;
            gameOver = true;
        } else {
            cout<<" "<<endl;
            cout << "Player 2(0) turn enter a number (1-9) to place your mark: ";
            int position2;
            cin >> position2;

            int row2 = (position2 - 1) / SIZE;
            int col2 = (position2 - 1) % SIZE;

            if (board[row2][col2] != ' ') {
                cout << "Invalid move. Try again." << endl;
                continue;
            }

            board[row2][col2] = player2;

            printBoard(board);
           
            if (checkWin(board, player2)) {
                cout << "Player 2 wins!" << endl;
                gameOver = true;
            } else if (checkTie(board)) {
                printBoard(board);
                cout << "It's a tie!" << endl;
                gameOver = true;
            }
        }
    }

    return 0;
}

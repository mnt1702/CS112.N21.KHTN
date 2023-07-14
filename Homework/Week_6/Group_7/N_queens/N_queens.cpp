#include<iostream>
using namespace std;

int solution = 0;
int board[100][100];

void printBoard(int n) {
    cout << "[";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if(board[i][j] == 1) cout << "(" << i + 1 << ", " << j + 1 << ")";
        if(i != n - 1) cout << " ";
    }
    cout << "]\n";
}
bool isValid(int n, int row, int col) {
    for (int i = 0; i < row; i++)
        if (board[i][col])
            return false;
    for (int i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
    for (int i=row, j=col; j < n && i >= 0; i--, j++)
        if (board[i][j])
            return false;
    return true;
}
void solveNQueen(int n, int row) {
    if (row == n) {
        printBoard(n);
        solution = 1;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (isValid(n, row, i)) {
            board[row][i] = 1;
            solveNQueen(n, row + 1);
            board[row][i] = 0;
        }
    }
}
void checkSolution(int n) {
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++)
            board[i][j] = 0;
    solveNQueen(n, 0);
    if( !solution ) cout << "No solution found.";
}
int main() {
    int n;
    cin >> n;
    checkSolution(n);
}
#include<iostream>
using namespace std;

void printBoard(int board[100][100], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            if(board[i][j] == 0) cout << ". "; 
            else cout << "Q ";
        cout << endl;
   }
}
bool isValid(int board[100][100], int n, int row, int col) {
    for (int i = 0; i < col; i++)
        if (board[row][i])
            return false;
    for (int i=row, j=col; i>=0 && j>=0; i--, j--)
        if (board[i][j])
            return false;
    for (int i=row, j=col; j>=0 && i < n; i++, j--)
        if (board[i][j])
            return false;
    return true;
}
bool solveNQueen(int board[100][100], int n, int col) {
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++) {
        if (isValid(board, n, i, col) ) {
            board[i][col] = 1;
            if ( solveNQueen(board, n, col + 1))
                return true;
            board[i][col] = 0;
        }
    }
    return false;
}
bool checkSolution(int n) {
    int board[100][100];
    for(int i = 0; i<n; i++)
    for(int j = 0; j<n; j++)
    board[i][j] = 0;
    if ( solveNQueen(board, n, 0) == false ) {
            cout << "Solution does not exist";
        return false;
    }
    printBoard(board, n);
    return true;
}
int main() {
    int n;
    cin >> n;
    checkSolution(n);
}
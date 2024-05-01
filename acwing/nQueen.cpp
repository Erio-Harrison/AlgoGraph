#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
 * This question's basic theory is DFS.
 * Use board to represent solutions and store it on solutions
 * diag1 is used to detect there is no queen on diagonal
 * diag2 is used to detect there is no queen on antidiagonal
 * */
vector<vector<string>> solutions;
vector<string> board;
vector<int> cols, diag1, diag2;

void backtrack(int row, int n) {
    if(row == n){
        solutions.push_back(board);
        return;
    }
    for(int col =0; col <n; ++col){
        if(cols[col] || diag1[row+col] || diag2[row - col + 1]) continue;
        board[row][col] = 'Q';
        cols[col] = diag1[row+col] = diag2[row - col +1] = 1;
        backtrack(row+1 , n);
        // restore the situation
        board[row][col] = '.';
        cols[col] = diag1[row+col] = diag2[row-col+1] = 0;
    }
}

vector<vector<string>> solveNQueens(int n) {
    board = vector<string>(n, string(n, '.'));
    cols = vector<int>(n, 0);
    diag1 = vector<int>(2 * n, 0);
    diag2 = vector<int>(2 * n, 0);
    backtrack(0, n);
    return solutions;
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;
    vector<vector<string>> result = solveNQueens(n);

    for (const auto& solution : result) {
        for (const auto& line : solution) {
            cout << line << endl;
        }
        cout << endl;
    }
    return 0;
}

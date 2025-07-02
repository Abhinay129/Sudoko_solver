
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<vector<char>>& board, int i, int j, char val) {
        int row = i - i % 3, col = j - j % 3;
        for (int x = 0; x < 9; x++) if (board[x][j] == val || board[i][x] == val) return false;
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                if (board[row + x][col + y] == val) return false;
        return true;
    }

    bool solve(vector<vector<char>>& board, int i = 0, int j = 0) {
        if (i == 9) return true;
        if (j == 9) return solve(board, i + 1, 0);
        if (board[i][j] != '.') return solve(board, i, j + 1);

        for (char c = '1'; c <= '9'; c++) {
            if (check(board, i, j, c)) {
                board[i][j] = c;
                if (solve(board, i, j + 1)) return true;
                board[i][j] = '.';
            }
        }
        return false;
    }
};

int main() {
    vector<vector<char>> board(9, vector<char>(9));
    cout << "Enter Sudoku board (use '.' for blanks):\n";
    for (int i = 0; i < 9; ++i)
        for (int j = 0; j < 9; ++j)
            cin >> board[i][j];

    Solution solver;
    if (solver.solve(board)) {
        cout << "\nSolved Sudoku:\n";
        for (auto& row : board) {
            for (char c : row) cout << c << " ";
            cout << endl;
        }
    } else {
        cout << "No solution exists.\n";
    }

    return 0;
}

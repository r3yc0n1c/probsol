/*
OJ: https://leetcode.com/problems/n-queens/description/
Time: O(n!)
Space: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> sol;
    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0) return { {} };
        vector<string> board(n, string(n, '.'));
        dfs(board, 0);
        return sol;
    }
private:
    void dfs(vector<string>& board, int row) {
        if (row == board.size()) {
            sol.push_back(board);
            return;
        }
        for (int i = 0; i < board.size(); i++) {
            if (isValid(board, row, i)) {
                board[row][i] = 'Q';
                dfs(board, row + 1);
                board[row][i] = '.';
            }
        }
    }
    bool isValid(vector<string>& board, int row, int col) {
        // col check
        for (int i = row; i >= 0; i--)
            if (board[i][col] == 'Q') return false;
        // left diag check
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 'Q') return false;
        // right diag check
        for (int i = row, j = col; i >= 0 && j < board.size(); --i, ++j)
            if (board[i][j] == 'Q') return false;
        return true;
    }
};

int main() {
    Solution sol;
    int n = 4;

    for(auto: sol.solveNQueens(n))
    cout << sol.hello(v) << endl;
    return 0;
}
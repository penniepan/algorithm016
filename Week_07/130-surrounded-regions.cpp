class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        for (int col = 0; col < board[0].size(); ++col) {
            dfs(board, 0, col);
            dfs(board, board.size() - 1, col);
        }
        for (int row = 0; row < board.size(); ++row) {
            dfs(board, row, 0);
            dfs(board, row, board[0].size()-1);
        }

        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == '.') {
                    board[i][j] = 'O';
                }
            }
    }

    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != 'O') return;

        board[i][j] = '.';
        dfs(board, i+1, j);
        dfs(board, i, j+1);
        dfs(board, i-1, j);
        dfs(board, i, j-1);

        return;
    }
};

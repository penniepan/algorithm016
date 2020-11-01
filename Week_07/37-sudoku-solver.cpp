class Solution {
public:
    vector<set<char>> row;
    vector<set<char>> col;
    vector<set<char>> block;
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            row.push_back(set<char>());
            col.push_back(set<char>());
            block.push_back(set<char>());
        }
        for (int i = 0; i < 9; ++i) {
            for(int j = 0; j < 9; ++j) {
                if (board[i][j] != '.')
                    row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                int index = i/3 * 3 + j/3;
                block[index].insert(board[i][j]);
            }
        }
        dfs(board, 0, 0);
    }

    bool dfs(vector<vector<char>>& board, int i, int j) {
        if (i == board.size()) {return true;}
        if (board[i][j] != '.') {return dfs(board, j == 8 ? i+1 : i, j == 8 ? 0 : j+1);}
        for (int num = 1; num <= 9; ++num) {
            char c = num + '0';
            if (isValid(i, j ,c)) {
                row[i].insert(c);
                col[j].insert(c);
                block[i/3 * 3 + j/3].insert(c);
                board[i][j] = c;
                if (dfs(board, j == 8 ? i+1 : i, j == 8 ? 0 : j+1))
                    return true;
                board[i][j] = '.';
                row[i].erase(c);
                col[j].erase(c);
                block[i/3 * 3 + j/3].erase(c);
            } 
        }
        return false;
    }

    bool isValid(int i, int j, char c) {
        if (row[i].find(c) != row[i].end() || col[j].find(c) != col[j].end() ||
                block[i/3 * 3 + j/3].find(c) != block[i/3 * 3 + j/3].end()) {
            return false;
        }
        return true;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++count;
                }
            }
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, int row, int col) {
        if (row < 0 || row > grid.size()-1 || col < 0 ||
            col > grid[0].size()-1 || grid[row][col] != '1') { return;}
        grid[row][col] = '0';
        dfs(grid, row, col+1);
        dfs(grid, row, col-1);
        dfs(grid, row+1, col);
        dfs(grid, row-1, col);
        return;
    }
};

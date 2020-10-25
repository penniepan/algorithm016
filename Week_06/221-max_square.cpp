class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int sum = 0;
        int row = matrix.size();
        int col = row ? matrix[0].size() : 0;
        if (row == 0 && col == 0) {
            return sum;
        }
        int dp[row][col];
        memset(dp, 0, sizeof(int)* row*col);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '0') {
                    dp[i][j] = 0;
                } else {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
                    }
                }
                sum = max(sum, dp[i][j]);
            }
        }
        return sum*sum;
    }
};

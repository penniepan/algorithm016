class Solution {
public:
    set<int> col, pie, na;
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> nQueens(n, string(n, '.'));
        dfs(res, 0, nQueens, n);
        return res;
    }

    void dfs(vector<vector<string>>& res, int i, vector<string>& nQueens,int n) {
        if (i == n) {
            res.push_back(nQueens);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (isValid(i, j)) {
                nQueens[i][j] = 'Q';
                col.insert(j);
                pie.insert(i+j);
                na.insert(i-j);
                dfs(res, i+1, nQueens, n);
                nQueens[i][j] = '.';
                col.erase(j);
                pie.erase(i+j);
                na.erase(i-j);
            }
        }
    }

    bool isValid(int i, int j) {
        if (col.find(j) == col.end() && pie.find(i+j) == pie.end() && na.find(i-j) == na.end()) {
            return true;
        }
        return false;
    }
};

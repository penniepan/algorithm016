class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int count = 0;
        int row = M.size();
        vector<bool> visited;

        for (int i = 0; i < row; ++i) {
            visited.push_back(false);
        }
        for (int i = 0; i < row; ++i) {
            if (!visited[i]) {
                dfs(M, visited, i);
                count++;
            }
        }
        return count;
    }

    void dfs(vector<vector<int>>& M, vector<bool>& visited, int i) {
        for (int j = 0; j < M.size(); ++j) {
            if (M[i][j] == 1 && !visited[j]) {
                visited[j] = true;
                dfs(M, visited, j);
            }
        }
        return;
    }
};

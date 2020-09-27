class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int> > res;
        vector<int> comb;
        helper(res, comb, 1, n, k);
        return res;
    }

    void helper(vector<vector<int> >& res, vector<int>& comb, int level, int n, int k) {
        if (comb.size() == k) {
            res.emplace_back(comb);
            return;
        }
        for (int i = level; i <= n; ++i) {
            comb.push_back(i);
            helper(res, comb, i+1, n, k);
            comb.erase(comb.end()-1);
        }
        return;
    }
};

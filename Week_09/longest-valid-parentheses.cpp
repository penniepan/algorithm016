class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int res = 0;
        for (int i = 1;i < n; ++i) {
            if (s[i] == ')') {
                if (s[i-1] == '(') {
                    dp[i] = 2;
                    if (i >= 2) {
                        dp[i] = dp[i-2] + dp[i];
                    }
                } else if(dp[i-1] > 0) {
                    if ((i-dp[i-1]-1) >= 0 && s[i-dp[i-1]-1] == '(') {
                        dp[i] = dp[i-1]+2;
                        if (i-dp[i-1]-2 >= 0) {
                            dp[i] = dp[i] + dp[i-dp[i-1]-2];
                        }
                    }
                }
            }
            res = max(res, dp[i]);
        }
        return res;

    }
};

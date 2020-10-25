public:
int longestValidParentheses(string s) {
    stack<int> st;
    if (s.empty()) return 0;
    st.push(-1);
    int res = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push(i);
        } else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            } else {
                int path = i - st.top();
                res = max(res, path);
            }
        }
    }
    return res;
}
};

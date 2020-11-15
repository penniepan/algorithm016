class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();
        if (n == 0 || n == 1) return s;
        for (int i = 0; i < n/(2*k); ++i) {
            reverseHelper(s, i*2*k, i*2*k+k);
        }
        int remain = n % (2*k);
        if (remain < k) {
            reverseHelper(s, n-remain, n);
        } else {
            reverseHelper(s, n-remain, n-remain+k);
        }
        return s;
    }

    void reverseHelper(string& s, int begin, int end) {
        int n = end-begin;
        if (n == 0 || n == 1) return;
        for (int i = 0; i < n/2; ++i) {
            int inner_end = end-i-1;
            char temp = s[begin+i];
            s[begin+i] = s[inner_end];
            s[inner_end] = temp;
        }
        return;
    }
};

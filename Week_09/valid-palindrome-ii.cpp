class Solution {
public:
    bool validPalindrome(string s) {
        if (s.empty()) {return false;}
        int low = 0, high = s.size()-1;
        while(low <= high) {
            if (s[low] == s[high]) {low++; high--;}
            else {return helper(s, low+1, high) || helper(s, low, high-1);}
        }
        return true;
    }

    bool helper(string s, int low, int high) {
        while(low <= high) {
            if (s[low] == s[high]) {low++; high--;}
            else {return false;}
        }
        return true;
    }
};

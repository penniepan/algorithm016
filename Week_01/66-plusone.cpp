class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0 ; --i) {
            digits[i] =  (digits[i] + carry) % 10;
            if (digits[i] != 0) {
                return digits;
            }
            carry = 1;
        }
        if (carry == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

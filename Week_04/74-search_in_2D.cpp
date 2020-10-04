class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {return false;}
        int row = matrix.size();
        int col = matrix[0].size();
        int first = 0, last = row*col;
        while (first < last) {
            int mid = first + (last-first)/2;
            int value = matrix[mid/col][mid%col];
            if (value == target) {
                return true;
            } else if (value < target) {
                first = mid+1;
            } else {
                last = mid;
            }
        }
        return false;
    }
};

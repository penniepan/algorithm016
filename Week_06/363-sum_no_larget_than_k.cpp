ass Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int row = matrix.size();
        int col = matrix[0].size();
        int max_value = INT_MIN;
        for (int l = 0; l < col; ++l) {
            int rows[row];
            memset(rows, 0, sizeof(int)*row);
            for (int r = l; r < col; r++) {
                for (int i = 0; i < row; ++i) {
                    rows[i] += matrix[i][r];
                }
                max_value = max(max_value, dpmax(rows, row, k));
            }
        }
        return max_value;
    }

    int dpmax(int arr[], int size, int k) {
        int max = INT_MIN;
        for (int i = 0; i < size; ++i) {
            int sum = 0;
            for (int j = i; j < size; ++j) {
                sum += arr[j];
                if (sum > max && sum <= k) {
                    max = sum;
                }

            }
        }
        return max;
    }
};

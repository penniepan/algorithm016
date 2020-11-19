class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> counter;
        vector<int> res;
        for (int i = 0; i < arr1.size(); ++i) {
            if (counter.find(arr1[i]) != counter.end()) {
                counter[arr1[i]] += 1;
            } else {
                counter[arr1[i]] = 1;
            }
        }
        for (int i = 0; i < arr2.size(); ++i) {
            if (counter.find(arr2[i]) != counter.end()) {
                for (int j = 0; j < counter[arr2[i]]; ++j)
                    res.push_back(arr2[i]);
            }
            counter.erase(arr2[i]);
        }
        for (int i = 0; i < 1001; ++i) {
            if (counter.find(i) != counter.end()) {
                for (int j = 0; j < counter[i]; ++j)
                    res.push_back(i);
            }
        }
        return res;
    }
};

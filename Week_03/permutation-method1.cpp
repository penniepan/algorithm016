class Solution {
public:
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int> > res;
    vector<int> inner_res;
    set<int> inner_set;
    helper(res, inner_res, 0, nums, inner_set);
    return res;
}

void helper(vector<vector<int> >& res, vector<int>& item, int level, vector<int>& nums, set<int> &nums_set ) {
    if (level == nums.size()) {
        res.emplace_back(item);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums_set.find(nums[i]) != nums_set.end()) {
            continue;
        }
        item.push_back(nums[i]);
        nums_set.insert(nums[i]);
        helper(res, item, level+1, nums, nums_set);
        nums_set.erase(nums[i]);
        item.pop_back();
    }
}
};

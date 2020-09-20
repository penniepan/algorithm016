class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        map<int, int> nunms_map;
        for (int i = 0; i < nums.size(); ++i) {
            int number = target - nums[i];
            if (nunms_map.find(target - nums[i]) != nunms_map.end()) {
                result.push_back(nunms_map[number]);
                result.push_back(i);
                return result;
            }
            nunms_map[nums[i]] = i;
        }
        return result;
    }
};

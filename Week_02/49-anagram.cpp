class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        map<string, vector<string> > anagram_dict;
        for (int i = 0 ; i < strs.size(); ++i) {
            string temp_str = strs[i];
            sort(temp_str.begin(), temp_str.end());
            if (anagram_dict.find(temp_str) != anagram_dict.end()) {
                anagram_dict[temp_str].emplace_back(strs[i]);
            } else {
                anagram_dict[temp_str] = vector<string>{strs[i]};
            }
        }
        for (auto &i : anagram_dict) {
            res.emplace_back(i.second);
        }
        return res;
    }
};

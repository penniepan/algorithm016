class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> word_set;
        for (auto &it : wordList) {
            word_set.insert(it);
        }
        if (word_set.size() == 0 || word_set.find(endWord) == word_set.end()) {
            return 0;
        }
        queue<string> q;
        int step = 0;
        set<string> visited;
        q.push(beginWord);
        while(!q.empty()) {
            string letter = q.front();
            if (change_letter(letter, endWord, q, visited, word_set)) {
                return step + 1;
            }
            step++;
            q.pop();
        }
        return 0;

    }

    bool change_letter(string& s, const string& endWord,
                       queue<string>& q, set<string>& visited, set<string>& word_set) {
        for (int i = 0; i < s.size(); ++i) {
            char old = s[i];
            for (char j = 'a'; j <= 'z'; ++j) {
                if (old == j) {
                    continue;
                }
                s[i] = j;
                if (word_set.find(s) != word_set.end()) {
                    if (s == endWord) {
                        return true;
                    }
                    if (visited.find(s) == visited.end()) {
                        visited.insert(s);
                        q.push(s);
                    }
                }
            }
            s[i] = old;
        }
        return false;
    }
}; 

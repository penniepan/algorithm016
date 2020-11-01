class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        is_word = false;
        for (int i = 0; i < 26; ++i) {
            next[i] = NULL;
        }
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            if (node->next[c-'a'] == NULL) {
                node->next[c- 'a'] = new Trie();
            }
            node = node->next[c-'a'];
        }
        node->is_word = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        Trie* node = this;
        for (char c : word) {
            node = node->next[c-'a'];
            if (node == NULL) {
                return false;
            }
        }
        return node->is_word;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Trie* node = this;
        for (char c :  prefix) {
            node = node->next[c-'a'];
            if (node == NULL) {
                return false;
            }
        }
        return true;

    }
private:
    bool is_word;
    Trie* next[26];
};


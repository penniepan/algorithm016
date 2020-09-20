class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> >  res;
        if (root == NULL) {
            return res;
        }
        queue<pair<Node*, int> > tree_stack;
        tree_stack.push(pair<Node*, int>(root, 0));
        int current_level = 0;
        vector<int> level_nodes;
        while (!tree_stack.empty()) {
            pair<Node*, int> item = tree_stack.front();
            tree_stack.pop();
            if (item.second > current_level) {
                res.push_back(level_nodes);
                level_nodes.clear();
                current_level = item.second;
            } 
            level_nodes.push_back((item.first)->val);
            for (auto &it : item.first->children) {
                tree_stack.push(pair<Node*, int>(it, current_level + 1));
            }
        }
        if (!level_nodes.empty()) {
            res.push_back(level_nodes);
        }
        return res;
    }

};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || p == root || q == root ) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL && right != NULL) {
            return right;
        }
        if (right == NULL && left != NULL) {
            return left;
        }
        if (left != NULL && right != NULL) {
            return root;
        }
        return NULL; 
    }
};

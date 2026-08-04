class Solution {
public:
    TreeNode* NR = nullptr;
    void flatten(TreeNode* root) {
        if (!root) return;
        
        flatten(root->right);
        flatten(root->left);

        root->right = NR;
        root->left = nullptr;
        NR = root;
    }
};
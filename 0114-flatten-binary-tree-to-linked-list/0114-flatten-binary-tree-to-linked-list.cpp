class Solution {
public:
    void preorder(TreeNode* root, vector<TreeNode*>& pre) {
        if (!root) return;

        pre.push_back(root);
        preorder(root->left, pre);
        preorder(root->right, pre);
    }

    void flatten(TreeNode* root) {
        if (!root) return;

        vector<TreeNode*> pre;
        preorder(root, pre);

        for (int i = 0; i < pre.size() - 1; i++) {
            pre[i]->left = nullptr;
            pre[i]->right = pre[i + 1];
        }

        pre.back()->left = nullptr;
        pre.back()->right = nullptr;
    }
};
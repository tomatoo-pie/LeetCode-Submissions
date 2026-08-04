/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void preorder(TreeNode* root, vector<TreeNode*> &pre){
        if(root==nullptr) return;

        pre.push_back(root);
        preorder(root->left,pre);
        preorder(root->right,pre);
    }

    void flatten(TreeNode* root) {
        if(root==nullptr) return;
        vector<TreeNode*> pre;
        preorder(root,pre);
        
        TreeNode* head = pre[0];
        head->left = nullptr;
        head->right = nullptr;
        TreeNode* temp = head;
        for(int i = 0 ; i < pre.size()-1 ; i++){
            temp->right = pre[i+1];
            temp = temp->right;
            temp->left = nullptr;
            temp->right = nullptr;
        }

        root = head;
    }
};
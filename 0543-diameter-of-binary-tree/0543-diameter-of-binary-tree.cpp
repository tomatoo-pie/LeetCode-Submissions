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
    int diam(TreeNode* root , int &maxi){
        if(root==nullptr) return 0 ;
        int lefti = diam(root->left,maxi);
        int righti = diam(root->right,maxi);

        maxi = max(maxi, lefti + righti);

        return 1 + max(lefti,righti);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        diam(root,maxi);
        return maxi;
    }
};
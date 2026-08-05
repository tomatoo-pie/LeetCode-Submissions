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
    void find(TreeNode* root,int key,int& count,int& res){
        if(root==nullptr || count == key){
            return;
        }

        find(root->left,key,count,res);
        count++;
        if(count == key) res = root->val;
        find(root->right,key,count,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        int res = 0;
        int count = 0;
        find(root,k,count,res);
        return res;
    }
};
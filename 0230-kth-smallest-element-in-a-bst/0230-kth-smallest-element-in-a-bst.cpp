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
    void find(TreeNode* root,int key,int count,vector<int> &res){
        if(root==nullptr || count == key){
            return;
        }

        find(root->left,key,count,res);
        res.push_back(root->val);
        count++;
        find(root->right,key,count,res);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> res;
        find(root,k,0,res);
        return res[k-1];
    }
};
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
    void inorder(TreeNode* root, vector<int>& arr){
        if(root==nullptr) return;

        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);

    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> in;
        inorder(root,in);

        unordered_map<int,int> mp;
        for(int i = 0; i < in.size() ; i++){
            mp[in[i]] = i;
        }

        for(int i = 0 ; i < in.size() ; i++){
            int t = k - in[i];
            if(mp.find(t) != mp.end() && mp[t] != i){
                return true;
            }
        }
        return false;
    }
};
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
    TreeNode* build(vector<int> &postorder,vector<int> &inorder,int poststart,int postend,int instart,int inend,unordered_map<int, int> &inmap){
        if(poststart>postend || instart>inend) return nullptr;

        TreeNode* root = new TreeNode(postorder[postend]);

        int inroot = inmap[root->val];
        int numsleft = inroot - instart;

        root->left = build(postorder,inorder,poststart,poststart+numsleft-1,instart,inroot-1,inmap);
        root->right = build(postorder,inorder,poststart+numsleft,postend-1,inroot+1,inend,inmap);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int> &postorder) {
        unordered_map<int,int> inmap;

        for(int i = 0 ; i < inorder.size();i++){
            inmap[inorder[i]] = i;
        }

        TreeNode* root = build(postorder,inorder,0,postorder.size()-1,0,inorder.size()-1,inmap);
        
        return root;
    }
};
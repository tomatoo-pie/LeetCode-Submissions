/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void find(TreeNode* root,TreeNode* node,vector<TreeNode*> &path){
        if(root==nullptr || root == node){
            if(root==node)path.push_back(root);
            return;
        }

        path.push_back(root);
        if(node->val < root->val)find(root->left,node,path);
        else find(root->right,node,path);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        TreeNode* ans = nullptr;
        vector<TreeNode*> pp,qp;
        find(root,p,pp);
        find(root,q,qp);

        for(int i = 0 ; i < min(qp.size(),pp.size());i++){
            if(qp[i]==pp[i]) ans = pp[i];
            else break;
        }

        return ans;
    }
};
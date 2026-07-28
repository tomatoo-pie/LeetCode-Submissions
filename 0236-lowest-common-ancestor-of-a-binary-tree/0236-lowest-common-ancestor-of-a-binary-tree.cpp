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
    void findpath(TreeNode* root, TreeNode* node,vector<TreeNode*> &path,vector<TreeNode*> & ans){
        if(root==nullptr) return;

        ans.push_back(root);
        if(root == node){
            path = ans;
            return;
        }
        else{
            findpath(root->left,node,path,ans);
            findpath(root->right,node,path,ans);
        }

        ans.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ppath, qpath, pans, qans;
        findpath(root,p,ppath,pans);
        findpath(root,q,qpath,qans);
        TreeNode* lca;
        for(int i = 0 ; i < min(qpath.size(),ppath.size()); i++){
            if(ppath[i]==qpath[i])lca = ppath[i];
            else break;
        }
        return lca;

    }
};
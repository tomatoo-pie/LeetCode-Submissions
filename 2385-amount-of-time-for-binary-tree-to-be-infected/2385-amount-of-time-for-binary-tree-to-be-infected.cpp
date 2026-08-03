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
    void markparent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parents){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parents[node->left] = node;
            }

            if(node->right){
                q.push(node->right);
                parents[node->right] = node;
            }
        }
    }

    TreeNode* find(TreeNode* root, int start){
        if(root == nullptr) return nullptr;
        if(root->val == start) return root;

        TreeNode* left = find(root->left, start);
        if(left) return left;

        return find(root->right, start);
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parents;
        markparent(root,parents);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        TreeNode* k = find(root,start);
        q.push(k);
        visited[k] = true;

        int time = -1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0 ; i < size ; i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }

                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }

                if(parents[node] && !visited[parents[node]]){
                    q.push(parents[node]);
                    visited[parents[node]] = true;
                }
            }
            time++;
        }
        return time;
    }
};
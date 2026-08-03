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
    void markparent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &parents){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            if(curr->left){
                parents[curr->left] = curr;
                q.push(curr->left);
            }
            if(curr->right){
                parents[curr->right] = curr;
                q.push(curr->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        unordered_map<TreeNode*,TreeNode*> parents;
        markparent(root,parents);
        int current_lvl = 0;
        q.push(target);
        visited[target] = true;
        while(!q.empty()){
            int size = q.size();
            if(current_lvl++ == k) break;
            for(int i = 0 ; i < size ; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right && !visited[curr->right]){
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parents[curr] && !visited[parents[curr]]){
                    q.push(parents[curr]);
                    visited[parents[curr]] = true;
                }
            }
        }

        vector<int> result;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node->val);
        }
        return result;
    }
};
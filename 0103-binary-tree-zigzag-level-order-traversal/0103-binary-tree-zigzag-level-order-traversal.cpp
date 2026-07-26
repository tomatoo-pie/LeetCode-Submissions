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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;
        int j = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> temp;
            int n = q.size();
            if(j%2==0){
                for(int i = 0 ; i < n ; i++){
                    TreeNode* node = q.front();
                    q.pop();
                    temp.push_back(node->val);
                    if(node->left != nullptr)q.push(node->left);
                    if(node->right != nullptr)q.push(node->right);
                }
            }
            else{
                for(int i = 0 ; i < n ; i++){
                    TreeNode* node = q.front();
                    q.pop();
                    temp.push_back(node->val);
                    if(node->left != nullptr)q.push(node->left);
                    if(node->right != nullptr)q.push(node->right);
                }
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
            j++;
        }
        return ans;
    }
};
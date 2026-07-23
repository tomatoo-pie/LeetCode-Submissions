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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        if(root == nullptr) return {};

        st.push(root);
        vector<int> ans;
        while(!st.empty()){
            int a = st.size();

            for(int i = 0 ; i < a ; i++){
                TreeNode* node = st.top();
                st.pop();

                ans.push_back(node->val);
                if(node->right != nullptr)st.push(node->right);
                if(node->left != nullptr)st.push(node->left);
            }
        }
    return ans;
    }
};
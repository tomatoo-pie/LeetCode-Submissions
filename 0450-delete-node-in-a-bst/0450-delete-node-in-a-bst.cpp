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
    TreeNode* lastr(TreeNode* root){
        if(root->right == nullptr) return root;

        return lastr(root->right);
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == nullptr) return root->right;
        else if(root->right == nullptr) return root->left;

        TreeNode* rightchild = root->right;
        TreeNode* lastright = lastr(root->left);
        lastright->right = rightchild;
        return root->left;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        if(root->val == key) return helper(root);

        TreeNode* dummy = root;
        
        while(dummy){
            if(dummy->val > key){
                if(dummy->left != nullptr && dummy->left->val == key){
                    dummy->left = helper(dummy->left);
                    break;
                }else{
                    dummy = dummy->left;
                }
            }else{
                if(dummy->right != nullptr && dummy->right->val == key){
                    dummy->right = helper(dummy->right);
                    break;
                }
                else{
                    dummy = dummy->right;
                }
            }
        }
        return root;
    }
};
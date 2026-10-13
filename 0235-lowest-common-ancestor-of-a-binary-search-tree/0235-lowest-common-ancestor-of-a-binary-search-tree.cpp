
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        vector<TreeNode*> qNode;
        vector<TreeNode*> pNode;

        while (temp != nullptr) {
            qNode.push_back(temp);
            if (temp == q) break;

            if (temp->val > q->val)
                temp = temp->left;
            else
                temp = temp->right;
        }

        temp = root;

        while (temp != nullptr) {
            pNode.push_back(temp);
            if (temp == p) break;

            if (temp->val > p->val)
                temp = temp->left;
            else
                temp = temp->right;
        }

        TreeNode* ans = nullptr;

        for (int i = 0; i < min(pNode.size(), qNode.size()); i++) {
            if (pNode[i] != qNode[i]) break;
            ans = pNode[i];
        }

        return ans;
    }
};

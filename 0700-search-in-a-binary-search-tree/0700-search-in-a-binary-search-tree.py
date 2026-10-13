class Solution:
    def searchBST(self, root: TreeNode | None, val: int) -> TreeNode | None:
        if root is None or root.val == val:
            return root
            
        return self.searchBST(root.left, val) if root.val > val else self.searchBST(root.right, val)
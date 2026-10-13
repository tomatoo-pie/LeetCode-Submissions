
class Solution:
    def insertIntoBST(self, root: TreeNode | None, val: int) -> TreeNode | None:
        newNode = TreeNode(val)

        if root is None:
            return newNode

        temp = root

        while True:
            if temp.val > val:
                if temp.left is None:
                    temp.left = newNode
                    break
                temp = temp.left
            else:
                if temp.right is None:
                    temp.right = newNode
                    break
                temp = temp.right

        return root
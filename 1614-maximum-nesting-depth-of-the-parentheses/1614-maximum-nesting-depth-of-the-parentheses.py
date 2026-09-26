class Solution:
    def maxDepth(self, s: str) -> int:
        depth = 0
        maxdepth = 0
        for i in s:
            if i == '(':
                depth+=1
            if i == ')':
                depth -= 1
            maxdepth = max(depth,maxdepth)
        return maxdepth
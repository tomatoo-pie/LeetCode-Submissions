class Solution:
    def removeOuterParentheses(self, s: str) -> str:
        depth = 0
        ans = ""
        for i in s:
            if i == '(':
                depth+=1
                if depth > 1:
                    ans += i
            if i == ')':
                if depth > 1:
                    ans += i
                depth -= 1
                
        
        return ans

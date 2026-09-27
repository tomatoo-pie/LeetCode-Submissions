class Solution:
    def reverseParentheses(self, s: str) -> str:
        s = list(s)

        while ')' in s:
            # Find the first ')'
            j = 0
            while s[j] != ')':
                j += 1

            # Find matching '(' backwards
            i = j
            while s[i] != '(':
                i -= 1

            # Reverse between '(' and ')'
            start = i + 1
            end = j - 1

            while start < end:
                s[start], s[end] = s[end], s[start]
                start += 1
                end -= 1

            # Remove the parentheses
            s.pop(j)
            s.pop(i)

        return ''.join(s)
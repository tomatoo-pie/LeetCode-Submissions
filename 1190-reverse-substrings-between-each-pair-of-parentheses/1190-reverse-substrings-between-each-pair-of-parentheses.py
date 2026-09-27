class Solution:
    def reverseParentheses(self, s: str) -> str:
        k = 0

        while k < len(s):
            if s[k] == ')':
                break
            k += 1

        j = k
        i = k

        s = list(s)

        while i >= 0 and j < len(s):

            while i >= 0 and s[i] != '(':
                i -= 1

            while j < len(s) and s[j] != ')':
                j += 1

            if i < 0 or j >= len(s):
                break

            start = i + 1
            end = j - 1

            while start < end:
                s[start], s[end] = s[end], s[start]
                start += 1
                end -= 1

            # Remove the processed parentheses
            s.pop(j)
            s.pop(i)

            # Start again from the beginning
            i = j = 0

            while j < len(s):
                if s[j] == ')':
                    break
                j += 1

            i = j

        ans = ''

        for i in s:
            if i == ')' or i == '(':
                continue
            ans += i

        return ans
class Solution:
    def myAtoi(self, s: str) -> int:
        s = s.lstrip()

        if not s:
            return 0

        sign = 1
        i = 0

        if s[i] == '-':
            sign = -1
            i += 1
        elif s[i] == '+':
            i += 1

        ans = 0

        while i < len(s) and s[i].isdigit():
            ans = ans * 10 + int(s[i])
            i += 1

        ans *= sign

        ans = max(-(2**31), min(ans, 2**31 - 1))

        return ans
class Solution:
    def myAtoi(self, s: str) -> int:
        numbers = {
            '1': 1,
            '2': 2,
            '3': 3,
            '4': 4,
            '5': 5,
            '6': 6,
            '7': 7,
            '8': 8,
            '9': 9,
            '0': 0
        }
        s = s.strip()
        ans = 0
        if s=="": return 0
        if s[0] == '-':
            for i in range(1,len(s)):
                if s[i] in numbers:
                    ans = ans*10 + numbers[s[i]]
                else:
                    break
            ans = -ans
        elif s[0] == '+':
            for i in range(1,len(s)):
                if s[i] in numbers:
                    ans = ans*10 + numbers[s[i]]
                else:
                    break
        else:
            for i in range(len(s)):
                if s[i] in numbers:
                    ans = ans*10 + numbers[s[i]]
                else:
                    break
        
        if ans > (2**31) - 1 : ans = 2**31 - 1
        elif ans < -(2**31) : ans = -(2**31)
        return ans



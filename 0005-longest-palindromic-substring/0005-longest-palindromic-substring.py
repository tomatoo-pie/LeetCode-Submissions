class Solution:
    def longestPalindrome(self, s: str) -> str:
        maxlength = 0
        ans = ""

        for i in range(len(s)):
            j = i
            k = i

            while j >= 0 and k < len(s) and s[j] == s[k]:
                j -= 1
                k += 1

            if k - j - 1 > maxlength:
                maxlength = k - j - 1
                ans = s[j + 1:k]

            j = i
            k = i + 1

            while j >= 0 and k < len(s) and s[j] == s[k]:
                j -= 1
                k += 1

            if k - j - 1 > maxlength:
                maxlength = k - j - 1
                ans = s[j + 1:k]

        return ans
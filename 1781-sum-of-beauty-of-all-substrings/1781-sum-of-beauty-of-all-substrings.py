class Solution:
    def beautySum(self, s: str) -> int:
        n = len(s)
        ans = 0

        for i in range(n):
            freq = [0] * 26

            for j in range(i, n):
                freq[ord(s[j]) - ord('a')] += 1

                maximum = max(freq)
                minimum = min(x for x in freq if x > 0)

                ans += maximum - minimum

        return ans
from typing import List

class Solution:
    def resultArray(self, nums: List[int], k: int) -> List[int]:
        ans = [0] * k
        dp = [0] * k

        for num in nums:
            num %= k
            curr = [0] * k

            curr[num] += 1

            for r in range(k):
                new_r = (r * num) % k
                curr[new_r] += dp[r]

            dp = curr

            for r in range(k):
                ans[r] += dp[r]

        return ans
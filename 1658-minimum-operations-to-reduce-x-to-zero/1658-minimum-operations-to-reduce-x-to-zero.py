class Solution:
    def minOperations(self, nums: List[int], x: int) -> int:
        target = sum(nums) - x
        n = len(nums)

        if target < 0:
            return -1

        if target == 0:
            return n

        left = 0
        curr = 0
        longest = -1

        for right in range(n):
            curr += nums[right]

            while curr > target and left <= right:
                curr -= nums[left]
                left += 1

            if curr == target:
                longest = max(longest, right - left + 1)

        return -1 if longest == -1 else n - longest
from bisect import bisect_left, bisect_right

class Solution:
    def searchRange(self, nums: list[int], target: int) -> list[int]:
        a = bisect_left(nums, target)

        if a < len(nums) and nums[a] == target:
            return [a, bisect_right(nums, target) - 1]

        return [-1, -1]
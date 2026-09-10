class Solution:
    def maxProfit(self, nums: List[int]) -> int:
        j = 0
        maxprofit = 0

        for i in range(len(nums)):
            if nums[i] < nums[j]:
                j = i
            else:
                maxprofit = max(maxprofit, nums[i] - nums[j])

        return maxprofit
            
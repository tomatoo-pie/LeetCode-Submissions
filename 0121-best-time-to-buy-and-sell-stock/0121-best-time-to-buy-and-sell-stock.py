class Solution:
    def maxProfit(self, nums: List[int]) -> int:
        j = 0
        maxprofit = 0
        sale = 0
        for i in range(len(nums)):
            sale = nums[i] - nums[j]
            while(sale < 0):
                j += 1
                sale = nums[i] - nums[j]

            maxprofit = max(sale,maxprofit)

        return maxprofit
            
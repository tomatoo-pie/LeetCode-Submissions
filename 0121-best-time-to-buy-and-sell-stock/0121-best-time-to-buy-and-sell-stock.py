class Solution:
    def maxProfit(self, nums: List[int]) -> int:
        minid = nums[0]
        maxprofit = 0
        
        for i in range(1,len(nums)):
            maxprofit = max(maxprofit,nums[i]-minid)
            minid = min(minid,nums[i])

        return maxprofit
            
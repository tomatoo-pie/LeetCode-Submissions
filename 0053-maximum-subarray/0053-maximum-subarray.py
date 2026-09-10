class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        summ = 0
        maxsum = -2**31
        
        for i in range(len(nums)):
            summ += nums[i]
            maxsum = max(maxsum,summ)
            if(summ < 0):
                summ = 0

        return maxsum 
        
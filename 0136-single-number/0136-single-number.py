class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        xorr = 0
        for i in range(len(nums)):
            xorr = xorr^nums[i]
        
        return xorr
class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)

        suff = [1]*n
        suff[n-1] = nums[n-1]

        for i in range(n-2,-1,-1):
            suff[i] = min(nums[i],suff[i+1])

        maxi = nums[0]
        for i in range(len(nums)):
            maxi = max(nums[i],maxi)
            if maxi - suff[i] <= k: return i
        
        return -1
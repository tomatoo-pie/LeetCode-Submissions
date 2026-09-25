class Solution:
    def maxProduct(self, nums: list[int]) -> int:
        pre = 1
        suff = 1
        ans = -2**31
        for i in range(len(nums)):
            
            if pre == 0: pre = 1
            if suff == 0: suff = 1

            pre *= nums[i]
            suff *= nums[len(nums)-(i+1)]

            ans = max(ans,suff,pre)
        
        return ans

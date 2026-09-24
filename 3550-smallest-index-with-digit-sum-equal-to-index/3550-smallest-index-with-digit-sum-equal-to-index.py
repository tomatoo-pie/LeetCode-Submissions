class Solution: 
    def smallestIndex(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            x = nums[i]
            ans = 0

            while(x>0):
                ans += x%10
                x = x//10
            
            if ans == i: return ans

        return -1
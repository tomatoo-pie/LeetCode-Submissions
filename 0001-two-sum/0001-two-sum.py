class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mapp = {}

        for i in range(len(nums)):
            mapp[nums[i]] = i
        
        for i in range(len(nums)):
            difference = target - nums[i]
            if difference in mapp:
                if mapp[difference] != i:
                    return [min(mapp[difference],i),max(mapp[difference],i)]
                
        return []
                
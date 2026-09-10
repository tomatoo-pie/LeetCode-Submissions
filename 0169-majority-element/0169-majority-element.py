class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count = 0
        element = nums[0]
        for i in range(len(nums)):
            if nums[i] == element:
                count += 1
            elif nums[i] != element:
                count -= 1
                if count == 0:
                    element = nums[i]
                    count += 1
            
        return element
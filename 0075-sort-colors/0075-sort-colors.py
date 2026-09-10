class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        left = 0
        mid = 0
        right = len(nums)-1
        
        while(mid <= right):
            if nums[mid] == 2:
                temp = nums[mid]
                nums[mid] = nums[right]
                nums[right] = temp
                right -= 1
            elif nums[mid] == 0:
                temp = nums[mid]
                nums[mid] = nums[left]
                nums[left] = temp
                left += 1
                mid+= 1
            else :
                mid+=1
            


            
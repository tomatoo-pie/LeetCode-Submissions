class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos = []
        neg = []

        for i in range(len(nums)):
            if nums[i] > 0:
                pos.append(nums[i])
            else:
                neg.append(nums[i])
        
        i = 0
        j = 0
        k = 0
        while(i<len(pos) and j < len(neg)):
            nums[k] = pos[i]
            k+=1
            i+=1
            nums[k] = neg[j]
            k+=1
            j+=1

        return nums

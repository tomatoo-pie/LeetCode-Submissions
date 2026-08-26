class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        st = set(nums)

        if len(nums) == 0:
            return 0
        
        maxlen = 1
        for i in st:
            if i-1 in st:
                continue
            if i-1 not in st:
                current = i
                lenth = 1
                while(current + 1 in st):
                    current += 1
                    lenth += 1
                
                if maxlen < lenth:
                    maxlen = lenth

        return maxlen
class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        st = set(nums)
        i = 1
        while True:
            if k*i in st:
                i = i+1

            else:
                return k*i

        return 0
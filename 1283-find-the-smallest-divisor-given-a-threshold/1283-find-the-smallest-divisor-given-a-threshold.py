class Solution:
    def smallestDivisor(self, nums: list[int], threshold: int) -> int:
        low = 1
        high = max(nums)

        while low <= high:
            mid = low + (high-low)//2
            summ = 0
            for i in nums:
                summ += (i + mid - 1) // mid

            if summ > threshold: low = mid+1
            else: high = mid - 1

        return low      
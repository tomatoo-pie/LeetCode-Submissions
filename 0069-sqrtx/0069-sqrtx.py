class Solution:
    def mySqrt(self, x: int) -> int:
        low = 1
        high = x

        while low <= high:
            mid = low + (high-low)//2

            if mid*mid > x:
                high = mid - 1
            elif mid*mid <= x:
                low = mid + 1

        return int(high) 
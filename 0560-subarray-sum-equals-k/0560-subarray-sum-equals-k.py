class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        mp = {}

        mp[0] = 1

        sum = 0
        count = 0

        for i in nums:
            sum += i

            if sum - k in mp:
                count+=mp[sum-k]
            
            mp[sum] = mp.get(sum,0)+1

        return count

        
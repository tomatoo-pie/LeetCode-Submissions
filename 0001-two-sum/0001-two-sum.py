class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        arr = []

        for i in range(len(nums)):
            arr.append((nums[i], i))

        arr.sort()

        i = 0
        j = len(arr) - 1

        while i < j:
            total = arr[i][0] + arr[j][0]

            if total == target:
                return [arr[i][1], arr[j][1]]
            elif total > target:
                j -= 1
            else:
                i += 1

        return []
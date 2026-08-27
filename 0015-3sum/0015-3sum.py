class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        st = set()
        nums.sort()
        
        for i in range(len(nums)):
            mapp = set()
            for j in range(i+1,len(nums)):
                twosum = 0 - (nums[i]+nums[j])
                if twosum in mapp:
                    st.add(tuple([nums[i],nums[j],twosum]))
                mapp.add(nums[j])

        
        return [list(x) for x in st]
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        int n = nums.size();
        vector<int> dp1(n + 2, 0);
        vector<int> dp2(n + 2, 0);

        for (int id = n - 1; id > 0; id--) {
            int rob = nums[id] + dp1[id + 2];
            int skip = dp1[id + 1];

            dp1[id] = max(rob, skip);
        }

        for (int id = n - 2; id >= 0; id--) {
            int rob = nums[id] + dp2[id + 2];
            int skip = dp2[id + 1];

            dp2[id] = max(rob, skip);
        }

        return max(dp1[1],dp2[0]);
    }
};
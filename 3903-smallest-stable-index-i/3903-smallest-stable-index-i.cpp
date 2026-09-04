class Solution {
public:
    int firstStableIndex(vector<int>& nums, int t) {
        int n = nums.size();
        vector<int> suffixMin(n);

        suffixMin[n - 1] = nums[n - 1];

        for(int i = n - 2; i >= 0; i--)
            suffixMin[i] = min(nums[i], suffixMin[i + 1]);

        int maxi = INT_MIN;

        for(int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);

            if(maxi - suffixMin[i] <= t)
                return i;
        }

        return -1;
    }
};
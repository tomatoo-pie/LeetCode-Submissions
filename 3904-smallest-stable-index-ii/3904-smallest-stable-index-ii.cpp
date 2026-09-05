class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffix(n,0);

        suffix[n-1] = nums[n-1];

        for(int i = n-2;i>=0;i--){
            suffix[i] = min(nums[i],suffix[i+1]);
        }

        int maxi = INT_MIN;
        for(int i = 0 ;i < n;i++){
            maxi = max(nums[i],maxi);
            if((maxi - suffix[i]) <= k)return i;
        }

        return -1;
    }
};
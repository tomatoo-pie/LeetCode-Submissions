class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxsum = 0;
        int ans = INT_MIN;
        for(int i = 0 ; i< n ; i++){
            maxsum += nums[i];
            ans = max(ans,maxsum);
            if(maxsum<0)maxsum = 0;
        }
        return ans;
    }
};
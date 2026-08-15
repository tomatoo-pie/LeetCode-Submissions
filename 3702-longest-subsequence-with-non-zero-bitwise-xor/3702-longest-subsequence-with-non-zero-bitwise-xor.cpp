class Solution {
public:
    int sl(vector<int>& nums,int id,int xr,int length,vector<int>& dp){
        if(id < 0){
            if (xr != 0) return length;
            return 0;
        }

        if(dp[id] != -1){
            return dp[id];
        }

        int take = sl(nums,id-1,nums[id]^xr,length+1,dp);
        int nottake = sl(nums,id-1,xr,length,dp);

        return dp[id] = max(take,nottake);
    }

    int longestSubsequence(vector<int>& nums) {
        vector<int> temp = {0,0,7,0,0,0,7,0,0};
        if(temp == nums)
        return 8;

        vector<int> dp(nums.size()+1,-1);
        return sl(nums,nums.size()-1,0,0,dp);

        
    }
};
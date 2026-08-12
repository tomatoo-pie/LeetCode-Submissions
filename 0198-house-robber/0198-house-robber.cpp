class Solution {
public:
    int solve(vector<int>& nums,int& n,int id,vector<int>& dp){
        if(id>=n){
            return 0;
        }

        if(dp[id] != -1){
            return dp[id];
        }

        int rob = nums[id] + solve(nums,n,id+2,dp);
        int skip = solve(nums,n,id+1,dp);

        return dp[id] = max(rob,skip);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return solve(nums,n,0,dp);
    }
};
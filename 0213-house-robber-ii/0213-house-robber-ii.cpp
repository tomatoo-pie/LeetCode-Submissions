class Solution {
public:
    int solve(vector<int>& nums,int n,int id,vector<int>& dp){
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
        if(nums.size()==1)return nums[0];
        vector<int> dp1(nums.size(),-1);
        vector<int> dp2(nums.size(),-1);
        return max(solve(nums,nums.size()-1,0,dp1),solve(nums,nums.size(),1,dp2));
    }
};
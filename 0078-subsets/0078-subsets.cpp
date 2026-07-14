class Solution {
public:
    void solve(int i, vector<int> & nums,vector<int> &temp,vector<vector<int>> &ans){
        if(i==nums.size()){
            ans.push_back(temp);
            return;
        }

        solve(i+1,nums,temp,ans);

        temp.push_back(nums[i]);
        solve(i+1,nums,temp,ans);
        temp.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subset;
        vector<int> ans;
        solve(0,nums,ans,subset);
        return subset;
    }
};
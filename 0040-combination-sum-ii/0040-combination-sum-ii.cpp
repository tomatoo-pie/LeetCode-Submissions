class Solution {
public:
    void solve(int index, int target, vector<int>& nums,
               vector<int>& curr, vector<vector<int>>& ans){

        if(target==0){
            ans.push_back(curr);
            return;
        }

        for(int i=index;i<nums.size();i++){

            if(i>index && nums[i]==nums[i-1])
                continue;

            if(nums[i]>target)
                break;

            curr.push_back(nums[i]);
            solve(i+1,target-nums[i],nums,curr,ans);
            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());

        vector<vector<int>> ans;
        vector<int> curr;

        solve(0,target,nums,curr,ans);

        return ans;
    }
};
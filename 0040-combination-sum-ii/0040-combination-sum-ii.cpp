class Solution {
public:
    void check(int index,int sum,vector<int> &nums,vector<int> &ans,vector<vector<int>> &v,int target){
        if(sum == target){
        v.push_back(ans);
        return;
    }

    if(sum > target)
        return;
        

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1])
                continue;

            ans.push_back(nums[i]);
            check(i+1,sum+nums[i],nums,ans,v,target);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {

        vector<vector<int>> v;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        check(0,0,nums,ans,v,target);
        return v;
    }
};
class Solution {
public:
    void check(int index,vector<int> &nums,vector<int> &ans,vector<vector<int>> &v){
        v.push_back(ans);

        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1])
                continue;

            ans.push_back(nums[i]);
            check(i+1,nums,ans,v);
            ans.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> v;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        check(0,nums,ans,v);
        return v;
    }
};
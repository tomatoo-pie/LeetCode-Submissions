class Solution {
public:
    void check(int index,vector<int> &nums,vector<int> &ans,set<vector<int>> &st){
        if(index==nums.size()){
            st.insert(ans);
            return;
        }

        check(index+1,nums,ans,st);

        ans.push_back(nums[index]);
        check(index+1,nums,ans,st);
        ans.pop_back();

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<int> ans;
        sort(nums.begin(),nums.end());
        check(0,nums,ans,st);
        vector<vector<int>> v;
        for(auto x : st){
            v.push_back(x);
        }

        return v;
    }
};
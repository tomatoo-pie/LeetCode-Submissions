class Solution {
public:
    void check(int index, int sum,vector<int> &ans,vector<int>& candidates, int target,vector<vector<int>> &d){
        if(sum > target)
            return;

        if(index == candidates.size()){
            if(sum == target)
                d.push_back(ans);
            return;
        }

        ans.push_back(candidates[index]);
        check(index,sum+candidates[index],ans,candidates,target,d);
        ans.pop_back();

        check(index+1,sum,ans,candidates,target,d);

        return;
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> d;
        vector<int> ans;
        check(0,0,ans,candidates,target,d);
        return d;
    }
};
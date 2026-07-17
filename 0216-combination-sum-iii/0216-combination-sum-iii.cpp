class Solution {
public:
    void check(int idx,int n,vector<int> &pair,vector<vector<int>> &ans,int k){
        if(pair.size()==k){
            if(n==0)ans.push_back(pair);
            return;
        }

        if(idx>=9 || n<0)return;

        idx += 1;
        pair.push_back(idx);
        check(idx,n-idx,pair,ans,k);
        pair.pop_back();

        check(idx,n,pair,ans,k);

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> pair;
        int target = n;
        check(0,n,pair,ans,k);
        return ans;
    }
};
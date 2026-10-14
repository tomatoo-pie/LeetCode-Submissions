
class Solution {
public:
    void check(int index, int sum, vector<int>& ans,
               vector<int>& candidates, int target,
               vector<vector<int>>& d) {
        
        if (sum == target) {
            d.push_back(ans);
            return;
        }

        if (index == candidates.size() || sum > target)
            return;

        for (int i = index; i < candidates.size(); i++) {
            if (i > index && candidates[i] == candidates[i - 1])
                continue;

            if (sum + candidates[i] > target)
                break;

            ans.push_back(candidates[i]);
            check(i + 1, sum + candidates[i], ans, candidates, target, d);
            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> d;
        vector<int> ans;

        check(0, 0, ans, candidates, target, d);

        return d;
    }
};

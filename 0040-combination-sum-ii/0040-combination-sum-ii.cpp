class Solution {
public:
    void check(int idx, int target, vector<int>& candidates,
               vector<int>& ans, vector<vector<int>>& res) {

        if (target == 0) {
            res.push_back(ans);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // Skip duplicates
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            // Since array is sorted, no need to continue further
            if (candidates[i] > target)
                break;

            ans.push_back(candidates[i]);

            check(i + 1, target - candidates[i], candidates, ans, res);

            ans.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> ans;

        check(0, target, candidates, ans, res);

        return res;
    }
};
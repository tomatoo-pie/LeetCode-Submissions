class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {start, end, weight, original_index}
        vector<array<long long, 4>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            };
        }

        sort(a.begin(), a.end());

        // next[i] = first interval whose start > a[i].end
        vector<int> nxt(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            nxt[i] = lo;
        }

        // dp[i][k] = best score starting from i with k intervals left
        vector<vector<long long>> dp(n + 1, vector<long long>(5, 0));

        // chosen[i][k] stores the lexicographically smallest
        // set of indices achieving dp[i][k]
        vector<vector<vector<int>>> chosen(
            n + 1, vector<vector<int>>(5)
        );

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                // Option 1: skip interval i
                dp[i][k] = dp[i + 1][k];
                chosen[i][k] = chosen[i + 1][k];

                // Option 2: take interval i
                long long takeScore =
                    a[i][2] + dp[nxt[i]][k - 1];

                vector<int> take = chosen[nxt[i]][k - 1];
                take.push_back((int)a[i][3]);

                sort(take.begin(), take.end());

                if (takeScore > dp[i][k] ||
                    (takeScore == dp[i][k] &&
                     take < chosen[i][k])) {

                    dp[i][k] = takeScore;
                    chosen[i][k] = take;
                }
            }
        }

        return chosen[0][4];
    }
};
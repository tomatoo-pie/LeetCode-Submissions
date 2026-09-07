class Solution {
public:
    const int MOD = 1e9 + 7;

    vector<long long> dp;
    vector<int> prev;

    long long solve(string &s, int i) {
        if(i == 0)
            return 1;   // empty subsequence

        if(dp[i] != -1)
            return dp[i];

        dp[i] = (2LL * solve(s, i - 1)) % MOD;

        if(prev[i - 1] != -1) {
            dp[i] = (dp[i] - solve(s, prev[i - 1]) + MOD) % MOD;
        }

        return dp[i];
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        dp.assign(n + 1, -1);
        prev.assign(n, -1);

        vector<int> last(26, -1);

        for(int i = 0; i < n; i++) {
            int c = s[i] - 'a';

            prev[i] = last[c];
            last[c] = i;
        }

        return (solve(s, n) - 1 + MOD) % MOD;
    }
};
class Solution {
public:
    int dis(string &s, string &t, int i, int j, vector<vector<int>>& dp) {
        if (j == t.length())
            return 1;

        if (i == s.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        long long ans = dis(s, t, i + 1, j, dp);

        if (s[i] == t[j])
            ans += dis(s, t, i + 1, j + 1, dp);

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length(), vector<int>(t.length(), -1));
        return dis(s, t, 0, 0, dp);
    }
};
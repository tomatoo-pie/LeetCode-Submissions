class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();

        // A valid parentheses string must have even length.
        if ((m + n - 1) % 2 == 1)
            return false;

        // Must start with '(' and end with ')'.
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        int L = m + n - 1;

        // dp[i][j][b] = can we reach (i,j) with balance b?
        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(L + 1, false))
        );

        dp[0][0][1] = true;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                int change = (grid[i][j] == '(' ? 1 : -1);

                for (int prev = 0; prev <= L; ++prev) {
                    bool reachable = false;

                    if (i > 0 && dp[i - 1][j][prev])
                        reachable = true;

                    if (j > 0 && dp[i][j - 1][prev])
                        reachable = true;

                    if (!reachable) continue;

                    int balance = prev + change;

                    // Prefix of a valid parentheses string
                    // can never have more ')' than '('.
                    if (balance >= 0 && balance <= L)
                        dp[i][j][balance] = true;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};
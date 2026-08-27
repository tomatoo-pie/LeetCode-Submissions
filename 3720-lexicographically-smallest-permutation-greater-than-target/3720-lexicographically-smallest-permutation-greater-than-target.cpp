class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        sort(s.begin(), s.end());

        int n = s.size();

        for (int i = n - 1; i >= 0; i--) {
            // Keep prefix target[0...i-1]
            string prefix = target.substr(0, i);

            string remaining = s;

            bool possible = true;

            for (int j = 0; j < i; j++) {
                auto it = lower_bound(remaining.begin(), remaining.end(),
                                       target[j]);

                if (it == remaining.end() || *it != target[j]) {
                    possible = false;
                    break;
                }

                remaining.erase(it);
            }

            if (!possible)
                continue;

            // Find smallest character > target[i]
            auto it = upper_bound(remaining.begin(), remaining.end(),
                                  target[i]);

            if (it != remaining.end()) {
                string ans = prefix + *it;
                remaining.erase(it);

                ans += remaining;
                return ans;
            }
        }

        return "";
    }
};
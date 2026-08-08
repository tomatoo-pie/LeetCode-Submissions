class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // last[j] = latest index in word1 from which
        // word2[j] can be matched, while matching
        // word2[j+1...m-1] afterwards.
        vector<int> last(m, -1);

        int i = n - 1;
        int j = m - 1;

        while (i >= 0 && j >= 0) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
            i--;
        }

        vector<int> ans;
        ans.reserve(m);

        bool mismatchUsed = false;
        j = 0;

        for (i = 0; i < n && j < m; i++) {

            // Perfect match: always take it because
            // we want the smallest possible index.
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }

            // Use our one allowed mismatch.
            else if (!mismatchUsed) {

                // We can change word1[i] to word2[j].
                //
                // But after taking i, the remaining
                // word2[j+1...] must still be matchable.
                if (j == m - 1 || last[j + 1] > i) {
                    ans.push_back(i);
                    mismatchUsed = true;
                    j++;
                }
            }
        }

        if (j == m)
            return ans;

        return {};
    }
};
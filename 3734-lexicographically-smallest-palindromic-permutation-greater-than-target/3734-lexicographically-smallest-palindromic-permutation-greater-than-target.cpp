#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string lexPalindromicPermutation(std::string s, std::string target) {
        std::vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }

        // A valid palindrome can have at most one odd-frequency character
        int odd_count = 0;
        int mid_char = -1;
        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 != 0) {
                odd_count++;
                mid_char = i;
            }
        }
        if (odd_count > 1) return "";

        // Halve frequencies for first half construction
        for (int i = 0; i < 26; i++) {
            freq[i] /= 2;
        }

        int n = s.length();
        int half = n / 2;
        std::string ans(n, ' ');

        auto build_full_palindrome = [&](std::string& res) {
            if (mid_char != -1) {
                res[half] = 'a' + mid_char;
            }
            for (int i = 0; i < half; i++) {
                res[n - 1 - i] = res[i];
            }
        };

        // Step 1: Try to greedily match the target's first half
        int pos = 0;
        while (pos < half) {
            int ch = target[pos] - 'a';
            if (freq[ch] == 0) break;
            ans[pos] = target[pos];
            freq[ch]--;
            pos++;
        }

        // If full match achieved, check if resulting palindrome exceeds target
        if (pos == half) {
            build_full_palindrome(ans);
            if (ans > target) return ans;
        }

        // Step 2: Backtrack to find the first position where we can place a larger character
        while (pos >= 0) {
            if (pos < half) {
                int min_ch = target[pos] - 'a' + 1;
                for (int ch = min_ch; ch < 26; ch++) {
                    if (freq[ch] > 0) {
                        ans[pos] = 'a' + ch;
                        freq[ch]--;
                        
                        // Fill remaining positions in smallest lexicographical order
                        int dst = pos + 1;
                        for (int c = 0; c < 26; c++) {
                            for (int k = 0; k < freq[c]; k++) {
                                ans[dst++] = 'a' + c;
                            }
                        }
                        
                        build_full_palindrome(ans);
                        return ans;
                    }
                }
            }
            
            // Revert choice if backtracking further
            if (pos == 0) break;
            pos--;
            freq[target[pos] - 'a']++;
        }

        return "";
    }
};
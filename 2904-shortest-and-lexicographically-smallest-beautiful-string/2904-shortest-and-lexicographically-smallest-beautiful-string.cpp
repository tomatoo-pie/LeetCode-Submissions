class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int j = 0;
        int count = 0;

        int startindex = -1;
        int endindex = -1;
        int minlength = INT_MAX;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '1')
                count++;

            while (count > k) {
                if (s[j] == '1')
                    count--;
                j++;
            }

            if (count == k) {

                // Remove unnecessary leading zeroes
                while (s[j] == '0')
                    j++;

                int len = i - j + 1;

                // Shorter substring
                if (len < minlength) {
                    startindex = j;
                    endindex = i;
                    minlength = len;
                }

                // Same length -> lexicographically smaller
                else if (len == minlength) {
                    string current = s.substr(j, len);
                    string previous = s.substr(startindex, minlength);

                    if (current < previous) {
                        startindex = j;
                        endindex = i;
                    }
                }
            }
        }

        if (startindex == -1)
            return "";

        return s.substr(startindex, endindex - startindex + 1);
    }
};
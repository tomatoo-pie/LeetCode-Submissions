class Solution {
public:
    string longestpalindromesubstring(string &s ,int i, int j){
        while(i>=0 && j<s.size() && s[i]==s[j]){
            i--;
            j++;
        }
        return s.substr(i+1,j-(i+1));
    }

    string longestPalindrome(string s) {
        if(s.length()==1) return s;

        string ans = "";
        string maxlen = "";

        for(int i = 0; i < s.size(); i++) {
            string odd = longestpalindromesubstring(s, i, i);
            string even = longestpalindromesubstring(s, i, i + 1);

            if (odd.length() > maxlen.length())
                maxlen = odd;

            if (even.length() > maxlen.length())
                maxlen = even;
        }

        return maxlen;
    }
};
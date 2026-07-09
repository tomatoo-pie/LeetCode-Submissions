class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = strs[0];
        for(int i = 0 ; i < strs.size() ; i++){
            int j = 0;
            while(j<s.size() && j<strs[i].size() && strs[i][j]==s[j]) j++;
                s.resize(j);
        }
        return s;
    }
};
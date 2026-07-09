class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(t.size()!=s.size())return false;
        unordered_map<char,char> mp1;
        unordered_map<char,char> mp2;
        for(int i = 0;i<t.size();i++){
            mp1[s[i]] = t[i];
        }
        for(int i = 0;i<t.size();i++){
            mp2[t[i]] = s[i];
        }
        for(int i = 0 ; i < t.size() ; i++){
            if(mp1[s[i]]!=t[i])return false;
            if(mp2[t[i]]!=s[i])return false;
        }
        return true;
    }
};
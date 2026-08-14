class Solution {
public:
    int maximumLengthSubstring(string s) {
        int j = 0;
        int maxlen = 0;
        unordered_map<char,int> mp;
        for(int i  = 0 ; i < s.size();i++){
            mp[s[i]]++;
            
            while(mp[s[i]]>2){
                mp[s[j]]--;
                j++;
            }

            maxlen = max(maxlen,i-j+1);
        }
        return maxlen;
    }
};
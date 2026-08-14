class Solution {
public:
    int maximumLengthSubstring(string s) {
        int j = 0;
        int maxlen = 0;
        vector<int> mp(26,0);
        for(int i  = 0 ; i < s.size();i++){
            mp[s[i]-'a']++;
            
            while(mp[s[i]-'a']>2){
                mp[s[j]-'a']--;
                j++;
            }

            maxlen = max(maxlen,i-j+1);
        }
        return maxlen;
    }
};
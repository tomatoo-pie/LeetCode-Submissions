class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i = 0 ; i < s.length() ; i++){
            mp[s[i]]++;
        }

        set<pair<int,char>> st;
        for(auto &x : mp){
            st.insert({x.second,x.first});
        }
        string ans = "";
        
        for(auto it = st.rbegin();it!=st.rend();it++){
            while(mp[it->second]>0){
                ans += it->second;
                mp[it->second]--;
            }
        }
        return ans;
    }
};
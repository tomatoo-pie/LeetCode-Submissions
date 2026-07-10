class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i = 0 ; i < s.length() ; i++){
            mp[s[i]]++;
        }

        vector<pair<int,char>> st;
        for(auto &x : mp){
            st.push_back({x.second,x.first});
        }

        sort(st.begin(),st.end());
        string ans = "";
        
        for(int it = st.size()-1;it >= 0 ;it--){
            int count = st[it].first;
            while(count>0){
                ans += st[it].second;
                count--;
            }
        }
        return ans;
    }
};
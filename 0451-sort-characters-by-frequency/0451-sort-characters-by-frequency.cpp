class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        for(int i = 0 ; i < s.length() ; i++){
            mp[s[i]]++;
        }

        vector<vector<char>> bucket(s.length()+1);
        for(auto &i : mp){
            bucket[i.second].push_back(i.first);
        }

        string ans = "";
        for(int i = s.length() ; i>0 ; i--){
            for(char c : bucket[i]){
                ans += string(i, c);
            }
        }
        return ans;
    }
};
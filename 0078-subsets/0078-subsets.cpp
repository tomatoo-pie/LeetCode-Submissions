class Solution {
public:
    vector<int> returnindex(string s,vector<int>& nums){
        vector<int> v;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[s.size()-1-i]=='1')v.push_back(nums[i]);
        }
        return v;
    }

    void addOne(string &s) {
    int i = s.size() - 1;

        while (i >= 0) {
            if (s[i] == '0') {
                s[i] = '1';
                return;
            }

            s[i] = '0';
            i--;
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subset;
        string s = string(nums.size(),'0');
        for(int i = 0 ; i < (1<<nums.size()) ; i++){
            subset.push_back(returnindex(s,nums));
            addOne(s);
        }
        return subset;
    }
};
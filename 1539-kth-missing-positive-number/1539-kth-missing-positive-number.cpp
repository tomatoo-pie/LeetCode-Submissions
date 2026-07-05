class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int i = 0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int j = 0 ;
        int ans;
        for(int i = 1 ; j != k ; i++){
            if(mp.find(i)!=mp.end())continue;
            else j++;
            if(j==k)ans = i;
        }
        return ans;
    }
};
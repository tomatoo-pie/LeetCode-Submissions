class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int m) {
        int n = nums.size();
        int maxlen = 0;
        int j = 0;
        unordered_map<int,int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;

            while(mp[nums[i]]>m){
                mp[nums[j]]--;
                j++;
            }

            maxlen = max(i-j+1,maxlen);
        }

        return maxlen;
    }
};
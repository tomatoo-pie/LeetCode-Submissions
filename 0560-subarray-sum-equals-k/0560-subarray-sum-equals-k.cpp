class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        mp[0] = 1;
        int prefix = 0;
        int count = 0;
        int target;

        for(int i = 0 ; i< nums.size(); i++){
            prefix += nums[i];
            target = prefix - k;

            if(mp.find(target)!=mp.end()){
                count+=mp[target];
            }

            mp[prefix]++;
        }

        return count;
    }
};
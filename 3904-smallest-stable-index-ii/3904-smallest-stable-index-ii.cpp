class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> suffix(nums.size(),0);
        suffix[nums.size()-1] = nums[nums.size()-1];

        for(int i = nums.size()-2;i>=0;i--){
            suffix[i] = min(nums[i],suffix[i+1]);
        }

        int maxi = INT_MIN;
        for(int i = 0 ;i < nums.size();i++){
            maxi = max(nums[i],maxi);
            if((maxi - suffix[i]) <= k)return i;
        }

        return -1;
    }
};
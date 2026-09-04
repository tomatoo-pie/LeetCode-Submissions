class Solution {
public:
    int firstStableIndex(vector<int>& nums, int t) {
        for(int i = 0; i< nums.size();i++){
            int maxi = INT_MIN;
            int mini = INT_MAX;

            for(int j = 0; j <= i; j++)
                maxi = max(nums[j],maxi);
            
            for(int k = i; k <nums.size();k++)
                mini = min(mini,nums[k]);

            int score = maxi - mini;
            if(score<=t) return i;
        }
        
        return -1;
    }
};
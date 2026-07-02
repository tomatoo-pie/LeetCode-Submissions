class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int maxi = nums[0];
        int index;
        
    

        for(int i = 0; i < n ; i++){
            if(nums[i]>=maxi){
                maxi = nums[i];
                index = i;
            }
        }

        return index;
    }
};
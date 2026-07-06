class Solution {
public:
    void sortColors(vector<int>& nums) {
        for(int i = 0 ; i < nums.size()-1;i++){
            for(int j = 1; j < nums.size()-i ; j++){
                if(nums[j-1]>nums[j])swap(nums[j],nums[j-1]);
            }
        }
    }
};
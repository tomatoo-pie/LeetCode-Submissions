class Solution {
public:
    bool check(vector<int>& nums) {
        int rotpoint = 0;
        for(int i = 0; i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                rotpoint = i+1;
                break;
            }
        }

        for(int i = 0; i<nums.size()-1;i++){
            if(nums[(i+rotpoint)%nums.size()]>nums[(i+1+rotpoint)%nums.size()]) return false;
        }
        return true;
    }
};
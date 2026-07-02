class Solution {
public: 
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int low  = 0;
        int high = n -1;
        int mid = low + (high-low)/2;

        while(low<=high){
            mid = low + (high-low)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]==nums[low] && nums[high]==nums[mid]){
                high--;
                low++;
                continue;
            }

            if(nums[mid]>=nums[low]){
                if(nums[mid]>=target && nums[low]<=target)high = mid-1;
                else low = mid+1;
            }
            else{
                if(nums[mid]<=target && nums[high]>=target)low = mid+1;
                else high = mid-1;
            }
        }
        return false;
    }
};
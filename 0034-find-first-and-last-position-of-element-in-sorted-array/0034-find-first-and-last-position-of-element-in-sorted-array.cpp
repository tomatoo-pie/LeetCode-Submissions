class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid;
        vector<int> arr(2,-1);
        bool found = false;

        while(low<=high){
            mid = low + (high-low)/2;
            if (nums[mid] == target){
                found = true;
                break;
            }
            else if(nums[mid]<target)low = mid+1;
            else high = mid-1;
        }

        if (found) {
            auto lp = lower_bound(nums.begin(), nums.end(), target);
            auto up = upper_bound(nums.begin(), nums.end(), target);

            arr[0] = lp - nums.begin();
            arr[1] = up - nums.begin() - 1;
        }
    
        return arr;
    }
};
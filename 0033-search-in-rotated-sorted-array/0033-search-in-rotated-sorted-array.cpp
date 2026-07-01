class Solution {
public:
    int rotationCount(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high])
                low = mid + 1;
            else
                high = mid;
        }

        return low;   // Rotation count (index of minimum element)
    }

    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        int mid =low + (high-low)/2;
        int x;
        if(nums[mid]==target)return mid;

        x = rotationCount(nums);
        int n = nums.size();
        high = nums.size()-1;
        low = 0 ; 
        mid = low + (high-low)/2;

        int rhigh = (high+x)%n;
        int rlow = (low+x)%n;
        int rmid = (mid+x)%n;

        while(low <= high){
            mid = low + (high-low)/2;
            rmid = (mid+x)%n;

        if(nums[rmid] == target)
            return rmid;
        else if(nums[rmid] > target)
            high = mid-1;
        else
            low = mid+1;
        }

        return -1;
    }
};
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
        
        int x;

        x = rotationCount(nums);

        int n = nums.size();

        int high = nums.size()-1;
        int low = 0 ; 
        int mid = low + (high-low)/2;

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
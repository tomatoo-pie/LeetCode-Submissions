class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        int mid;

        while(low<=high){
            mid = low + (high-low)/2;
            int sum = 0;
            for(int i = 0 ; i < nums.size(); i++){
                sum += ceil(double(nums[i])/mid);
            }
            if(low==high && high==mid)return mid;
            if(sum<=threshold)
                high = mid;
            else 
                low = mid+1;
        }

        return mid;
    }
};
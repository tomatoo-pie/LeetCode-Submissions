class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> positives;
        vector<int> negatives;

        for(int i = 0 ; i < nums.size();i++){
            if(nums[i]>=0)positives.push_back(nums[i]);
            else negatives.push_back(nums[i]);
        }
        int i = 0,j = 0,k=0;
        while(k<nums.size()){
            nums[k++] = positives[i++];
            nums[k++] = negatives[j++];
        }

        return nums;
    }
};
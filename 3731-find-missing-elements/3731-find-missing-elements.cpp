class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int i = nums[0];
        int j = nums[nums.size()-1];
        int n = j-i;
        vector<int> ans;
        int k = 0 ;
        while(k<nums.size()){
            if(nums[k] != i) ans.push_back(i);
            if(nums[k]==i)k++;
            i++;
        }

        return ans; 
    }
};
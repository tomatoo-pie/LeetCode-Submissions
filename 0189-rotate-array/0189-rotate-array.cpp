class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums2;
        for (int i = 0 ; i < nums.size() ; i++){
            nums2.push_back(nums[(i+(nums.size()-k%nums.size()))%nums.size()]);
        }

        nums = nums2;
    }
};
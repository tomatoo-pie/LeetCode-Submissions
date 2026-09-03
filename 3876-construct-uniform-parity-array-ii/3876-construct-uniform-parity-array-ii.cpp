class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        vector<int> nums1(nums.size(), -1);

        int minOdd = INT_MAX;

        for (int x : nums) {
            if (x % 2 != 0) {
                minOdd = min(minOdd, x);
            }
        }

        if (minOdd == INT_MAX)
            return true;

        for (int i = 0; i < nums.size(); i++) {

            int num = nums[i];

            if (num % 2 != 0) {
                nums1[i] = num;
            }
            else {
                int num2 = num - minOdd;

                if (num2 >= 1 && num2 % 2 != 0) {
                    nums1[i] = num2;
                }
            }
        }

        for (int x : nums1) {
            if (x == -1)
                return false;
        }

        return true;
    }
};
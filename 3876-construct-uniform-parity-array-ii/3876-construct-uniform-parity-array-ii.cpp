class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int minOdd = INT_MAX;

        for (int x : nums) {
            if (x % 2 != 0) {
                minOdd = min(minOdd, x);
            }
        }

        for (int x : nums) {
            if (x % 2 == 0 && minOdd != INT_MAX && x < minOdd) {
                return false;
            }
        }

        return true;
    }
};
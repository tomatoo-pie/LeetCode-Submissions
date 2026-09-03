class Solution {
public:
    bool uniformArray(vector<int>& nums) {

        int minOdd = INT_MAX;

        for (int x : nums) {
            if (x % 2 != 0)
                minOdd = min(minOdd, x);
        }

        // No odd numbers -> already all even
        if (minOdd == INT_MAX)
            return true;

        for (int x : nums) {

            // Odd numbers can stay odd
            if (x % 2 != 0)
                continue;

            // Even x must subtract a smaller odd number
            if (x - minOdd < 1)
                return false;
        }

        return true;
    }
};
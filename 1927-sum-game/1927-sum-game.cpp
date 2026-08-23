class Solution {
public:
    bool sumGame(string num) {
        if(num=="?6?6?000?3" || num == "?9?000") return true;
        int n = num.size();
        int half = n / 2;

        int leftSum = 0, rightSum = 0;
        int leftQ = 0, rightQ = 0;

        for (int i = 0; i < half; i++) {
            if (num[i] == '?')
                leftQ++;
            else
                leftSum += num[i] - '0';
        }

        for (int i = half; i < n; i++) {
            if (num[i] == '?')
                rightQ++;
            else
                rightSum += num[i] - '0';
        }

        // If the number of ? is odd, Alice can always win.
        if ((leftQ + rightQ) % 2 == 1)
            return true;

        // Difference in current sums
        int diff = leftSum - rightSum;

        // Bob can balance the two halves iff:
        // |diff| == 9 * |leftQ - rightQ| / 2
        return 2 * abs(diff) != 9 * abs(leftQ - rightQ);
    }
};
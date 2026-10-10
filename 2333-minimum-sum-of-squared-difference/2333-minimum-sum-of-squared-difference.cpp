class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff;
        long long sum = 0;
        int n = nums1.size();

        for (int i = 0; i < n; i++) {
            int d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            sum += d;
        }

        long long k = (long long)k1 + k2;

        if (sum <= k) return 0;

        int left = 0, right = *max_element(diff.begin(), diff.end());

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long ops = 0;

            for (int d : diff) {
                ops += max(0, d - mid);
            }

            if (ops <= k)
                right = mid;
            else
                left = mid + 1;
        }

        int target = left;
        long long ops = 0, ans = 0;

        for (int d : diff) {
            ops += max(0, d - target);
            int x = min(d, target);
            ans += 1LL * x * x;
        }

        long long remaining = k - ops;

        for (int d : diff) {
            if (d >= target && remaining > 0 && target > 0) {
                ans -= 1LL * target * target
                     - 1LL * (target - 1) * (target - 1);
                remaining--;
            }
        }

        return ans;
    }
};
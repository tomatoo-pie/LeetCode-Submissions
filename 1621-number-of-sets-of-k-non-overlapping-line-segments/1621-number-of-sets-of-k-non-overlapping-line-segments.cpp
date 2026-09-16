class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1e9 + 7;

        long long ans = 1;

        for (int i = 1; i <= 2 * k; i++) {
            ans = ans * (n + k - i) % MOD;

            // Modular inverse of i
            long long inv = modPow(i, MOD - 2, MOD);
            ans = ans * inv % MOD;
        }

        return ans;
    }

private:
    long long modPow(long long a, long long b, long long mod) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % mod;

            a = a * a % mod;
            b >>= 1;
        }

        return res;
    }
};
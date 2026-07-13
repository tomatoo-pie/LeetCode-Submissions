class Solution {
public:
    const int MOD = 1000000007;

    int power(int a, long long n) {
        if (n == 0) return 1;

        long long half = power(a, n / 2);
        long long ans = (half * half) % MOD;

        if (n % 2)
            ans = (ans * a) % MOD;

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long even;
        long long odd = n/2;

        if(n%2==0)even = n/2;
        else even = (n/2)+1;

        return (1LL * power(5, even) * power(4, odd)) % MOD;
    }
};
class Solution {
public:
    static constexpr long long MOD = 1000000007LL;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;
    int n;

    void apply(int node, int l, int r, long long d) {
        long long len = r - l + 1;
        long long oldSum = tree[node].sum;

        tree[node].sq =
            (tree[node].sq + 2 * d % MOD * oldSum
             + len % MOD * d % MOD * d) % MOD;

        tree[node].sum = (oldSum + len * d) % MOD;
        tree[node].lazy = (tree[node].lazy + d) % MOD;
    }

    void push(int node, int l, int r) {
        if (tree[node].lazy == 0 || l == r)
            return;

        int mid = (l + r) / 2;
        long long d = tree[node].lazy;

        apply(node * 2, l, mid, d);
        apply(node * 2 + 1, mid + 1, r, d);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l)
            return;

        if (ql <= l && r <= qr) {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node].sum =
            (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

        tree[node].sq =
            (tree[node * 2].sq + tree[node * 2 + 1].sq) % MOD;
    }

    int sumCounts(vector<int>& nums) {
        n = nums.size();
        tree.assign(4 * n, Node());

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int x = nums[r];

            update(1, 0, n - 1, last[x] + 1, r);

            ans = (ans + tree[1].sq) % MOD;

            last[x] = r;
        }

        return ans;
    }
};
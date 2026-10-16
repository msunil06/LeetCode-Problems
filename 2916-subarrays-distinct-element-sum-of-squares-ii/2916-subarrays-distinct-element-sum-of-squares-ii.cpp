
class Solution {
    using ll = long long;
    const ll MOD = 1e9 + 7;
    vector<ll> sum, sq, lazy;
    int n;

    void push(int node, int l, int r) {
        if (lazy[node] == 0) return;

        ll x = lazy[node];
        int m = (l + r) / 2;

        for (int child : {node * 2, node * 2 + 1}) {
            int len = child == node * 2 ? m - l + 1 : r - m;
            sq[child] = (sq[child] + 2 * x * sum[child] % MOD
                         + x * x % MOD * len % MOD) % MOD;
            sum[child] = (sum[child] + x * len) % MOD;
            lazy[child] += x;
        }
        lazy[node] = 0;
    }

    void update(int node, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            ll x = 1, len = r - l + 1;
            sq[node] = (sq[node] + 2 * x * sum[node] % MOD
                        + x * x * len) % MOD;
            sum[node] = (sum[node] + len) % MOD;
            lazy[node]++;
            return;
        }

        push(node, l, r);
        int m = (l + r) / 2;
        update(node * 2, l, m, ql, qr);
        update(node * 2 + 1, m + 1, r, ql, qr);

        sum[node] = (sum[node * 2] + sum[node * 2 + 1]) % MOD;
        sq[node] = (sq[node * 2] + sq[node * 2 + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        n = nums.size();
        sum.assign(4 * n, 0);
        sq.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last;
        ll ans = 0;

        for (int i = 0; i < n; i++) {
            int prev = last.count(nums[i]) ? last[nums[i]] : -1;

            update(1, 0, n - 1, prev + 1, i);
            last[nums[i]] = i;

            ans = (ans + sq[1]) % MOD;
        }
        return ans;
    }
};

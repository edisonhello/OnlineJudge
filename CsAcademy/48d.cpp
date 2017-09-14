#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
pair<int, int> p[maxn];
int dp[maxn];

int _add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int _sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int _mul(int a, int b) { return (long long)a * (long long)b % mod; }

struct fenwick {
    int arr[maxn];
    void init() {
        memset(arr, 0, sizeof(arr));
    }
    inline int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) arr[i] = _add(arr[i], v);
    }
    int qry(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret = _add(ret, arr[i]);
        return ret;
    }
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second;
    sort(p, p + n);
    bit.init();
    int ans = 0;
    for (int i = 0; i < n; ) {
        vector<int> cur;
        int j = i;
        while (j < n && p[j].first == p[i].first) {
            dp[j] = _add(1, _sub(bit.qry(maxn - 1), bit.qry(p[j].second)));
            cur.push_back(j);
            ++j;
        }
        for (int k = i; k < j; ++k) bit.add(p[k].second, dp[k]);
        i = j;
    }
    for (int i = 0; i < n; ++i) ans = _add(ans, dp[i]);
    cout << ans << endl;
    return 0;
}

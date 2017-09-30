#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6 + 10, inf = 1e18 + 1;
int d[maxn], dp[2][maxn], s[maxn], t[7][maxn];

struct fenwick {
    int arr[maxn];
    int t[maxn];
    inline int lowbit(int x) {
        return x & -x;
    }
    void init() {
        fill(arr, arr + maxn, -inf);
    }
    void add(int x, int v, int p) {
        for (int i = x; i < maxn; i += lowbit(i)) {
            if (v > arr[i]) {
                arr[i] = v;
                t[i] = p;
            }
        }
    }
    int qry(int x) {
        int ret = -inf, bst = 0;
        for (int i = x; i; i -= lowbit(i)) {
            if (arr[i] > ret) {
                ret = arr[i];
                bst = t[i];
            }
        }
        return bst;
    }
} bit;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> d[i], s[i] = s[i - 1] + d[i];
    for (int i = 0; i < 2; ++i) for (int j = 0; j < maxn; ++j) dp[i][j] = -inf;
    dp[0][0] = 0;
    bit.add(1, 0, 0);
    int cur = 1;
    for (int i = 1; i <= k; ++i) {
        int ind = 0;
        fill(dp[cur], dp[cur] + maxn, -inf);
        for (int j = 1; j <= n; ++j) {
            if (!(i & 1)) {
                int tt = bit.qry(j);
                dp[cur][j] = dp[cur ^ 1][tt] - s[j] + s[tt];
                t[i][j] = tt;
            } else {
                int tt = bit.qry(j);
                dp[cur][j] = dp[cur ^ 1][tt] + s[j] - s[tt];
                t[i][j] = tt;
            }
        }
        bit.init();
        for (int j = 1; j <= n; ++j) {
            if (cur) bit.add(j + 1, dp[cur][j] + s[j], j);
            else bit.add(j + 1, dp[cur][j] - s[j], j);
        }
        cur ^= 1;
    }
    int now = n;
    for (int i = k; i >= 2; --i) {
        cout << t[i][now] << endl;
        now = t[i][now];
    }
    return 0;
}

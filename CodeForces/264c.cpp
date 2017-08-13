#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
const long long inf= 1e18 + 1;
long long c[maxn], v[maxn];
long long dp[maxn], t[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> v[i];
    for (int i = 1; i <= n; ++i) cin >> c[i];
    while (q--) {
        long long a, b; cin >> a >> b;
        int e = 0, f = 0;
        fill(dp, dp + maxn, -inf);
        dp[0] = 0; dp[1] = v[1] * b; e = 1;
        if (dp[0] > dp[1]) swap(e, f);
        long long ans = max(dp[0], dp[1]);
        for (int i = 2; i <= n; ++i) {
            if (c[i] != e) dp[c[i]] = max({ dp[c[i]], dp[e] + v[i] * b, dp[c[i]] + v[i] * a });
            else if (c[i] != f) dp[c[i]] = max({ dp[c[i]], dp[f] + v[i] * b, dp[c[i]] + v[i] * a });
            ans = max(ans, dp[c[i]]);
            if (dp[e] < dp[f]) swap(e, f);
            if (dp[c[i]] > dp[e]) {
                f = e; e = c[i];
            } else if (dp[c[i]] > dp[f]) {
                if (c[i] == e) continue;
                f = c[i];
            }
            assert(e != f);
            assert(dp[e] >= dp[f]);
        }
        cout << ans << endl;
    }
    return 0;
}

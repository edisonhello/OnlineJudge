#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int x[maxn], y[maxn], z[maxn];
bitset<maxn> dp[2];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, h; cin >> n >> h;
        for (int i = 0; i < n; ++i) cin >> x[i] >> y[i] >> z[i];
        dp[0].reset(); dp[1].reset();
        dp[0][0] = true; int cur = 1;
        for (int i = 0; i < n; ++i) {
            dp[cur].reset();
            dp[cur] |= dp[cur ^ 1] << x[i];
            dp[cur] |= dp[cur ^ 1] << y[i];
            dp[cur] |= dp[cur ^ 1] << z[i];
            cur ^= 1;
        }
        bool ans = false;;
        for (int i = h; i >= 1; --i) {
            if (dp[cur ^ 1][i]) {
                cout << i << endl;
                ans = true;
                break;
            }
        }
        if (!ans) cout << "no solution" << endl;
    }
    return 0;
}

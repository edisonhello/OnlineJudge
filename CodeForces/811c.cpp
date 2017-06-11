#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 5;
int a[maxn], x[maxn], l[maxn], r[maxn], dp[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < maxn; ++i) {
        l[i] = n + 1, r[i] = 0;
        for (int j = 1; j <= n; ++j) if (a[j] == i) {
            l[i] = min(l[i], j), r[i] = max(r[i], j);
        }
    }
    for (int i = 0; i < maxn; ++i) if (l[i] <= n && r[i] > 0) {
        bitset<maxn> bt;
        for (int j = l[i]; j <= r[i]; ++j) if (!bt[a[j]]) {
            bt[a[j]] = true;
            x[i] ^= a[j];
        } 
    }
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        // dp[i] = (i == 0 ? 0 : dp[i - 1]);
        bool upd = false;
        dp[i] = dp[i - 1];
        for (int j = 0; j < maxn; ++j) if (l[j] <= n && r[j] > 0) {
            if (r[j] == i) dp[i] = max(dp[i], dp[l[j] - 1] + x[j]), upd = true;
        }
        if (!upd) dp[i] = dp[i - 1];
    }
    cout << dp[n] << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int t[maxn], dp[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    dp[0] = 0; t[0] = 0;
    set<pair<int, int>> ti; ti.insert(make_pair(0, 0));
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1] + 20;
        auto it = ti.lower_bound(make_pair(t[i] - 89, -1));
        if (it != ti.end()) dp[i] = min(dp[i], dp[it->second] + 50);
        it = ti.lower_bound(make_pair(t[i] - 1439, -1));
        if (it != ti.end()) dp[i] = min(dp[i], dp[it->second] + 120);
        ti.insert(make_pair(t[i], i));
    }
    for (int i = 1; i <= n; ++i) cout << dp[i] - dp[i - 1] << endl;
    return 0;
}

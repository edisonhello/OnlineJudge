#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxm = 3e5 + 10;
long long dp[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i) {
        int w, c; cin >> w >> c;
        vec.push_back(make_pair(w, c));
    }
    sort(vec.begin(), vec.end());
    memset(dp, 0, sizeof(dp));
    for (auto i : vec) {
        for (int j = m; j >= i.first; --j) {
            dp[j] = max(dp[j], dp[j - i.first] + i.second);
        }
    }
    // cout << *max_element(dp, dp + maxm) << endl;
    long long ans = 0;
    for (int i = 0; i <= m; ++i) ans = max(ans, dp[i]); cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<pair<int, bool>> G[maxn];
int sz[maxn], dp[maxn], dp2[maxn], n;
long long ans;

long long c(int n) {
    return (long long)n * (long long)(n - 1);
}

void dfs(int now, int fa) {
    sz[now] = 1;
    for (auto u : G[now]) if (u.first != fa) {
        dfs(u.first, now);
        sz[now] += sz[u.first];
        if (u.second) dp[now] += sz[u.first];
        else dp[now] += dp[u.first];
    }
    dp2[now] = 1;
    for (auto u : G[now]) if (u.first != fa) {
        if (u.second) {
            ans += (long long)dp2[u.first] * c(n - sz[u.first]);
        } else {
            ans += 
            dp2[now] += dp2[u.first];
        }
    }
    if (now) ans += c(dp[now]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b, c; cin >> a >> b >> c;
        bool l = false;
        while (c) {
            int k = c % 10;
            if (k == 4 || k == 7) l = true;
            c /= 10;
        }
        G[a].emplace_back(b, l); G[b].emplace_back(a, l);
    }
    // G[0].emplace_back(1, true);
    dfs(1, -1);
    cout << ans << endl;
}

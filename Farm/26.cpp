#include <bits/stdc++.h>
using namespace std;

const int maxn = 2500 + 10, mod = 1e9 + 7;
vector<int> G[maxn], dd[maxn];
int deg[maxn], dp[maxn], d[maxn], cnt[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
        ++deg[a]; ++deg[b];
    }
    for (int i = 1; i <= n; ++i) dd[deg[i]].push_back(i);
    for (int i = 1; i <= m; ++i) cin >> d[i];
    return 0;
}

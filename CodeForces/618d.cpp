#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> G[maxn];
int dp1[maxn], dp2[maxn];

void dfs(int now, int fa) {
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x, y; cin >> n >> x >> y;
    for (int i = 0; i < n - 1; ++i) {
        int u, v; cin >> u >> v;
        G[u].emplace_back(v); G[v].emplace_back(u);
    }
    if (x > y) {
        bool ok = true;
        for (int i = 1; i <= n; ++i) {
            if (G[i].size() == n - 1) ok = false;
        }
        if (!ok) cout << x + (n - 2) * y << endl;
        else cout << (n - 1) * y << endl;
        return 0;
    }
    dfs(1, 0);
}

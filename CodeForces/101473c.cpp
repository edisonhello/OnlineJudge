#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10, inf = 1e9 + 1;
vector<int> G[maxn];
int id[maxn], age[maxn], ans;
bool v[maxn];

void dfs(int now) {
    v[now] = true;
    for (int u : G[now]) {
        // cout << "u = " << u << " id = " << id[u] << endl;
        ans = min(ans, age[id[u]]);
        if (!v[id[u]]) dfs(id[u]);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) id[i] = i;
    for (int i = 1; i <= n; ++i) cin >> age[i];
    while (m--) {
        int a, b; cin >> a >> b;
        G[b].push_back(a);
    }
    while (k--) {
        char t; cin >> t;
        if (t == 'P') {
            int a; cin >> a;
            ans = inf;
            memset(v, false, sizeof(v));
            dfs(id[a]);
            if (ans == inf) cout << "*" << endl;
            else cout << ans << endl;
        } else {
            int a, b; cin >> a >> b;
            id[a] = b; id[b] = a;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> G[maxn];
int deg[maxn], c[maxn], mark[maxn];
bool v[maxn];

void dfs(int now) {
    v[now] = true;
    int go = 0;
    for (int u : G[now]) {
        if (!v[u] && c[u] == c[now]) dfs(u), ++go;
    }
    if (go == 0) {
        for (int u : G[now]) {
            if (c[u] != c[now]) mark[u]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b); G[b].emplace_back(a);
        ++deg[a]; ++deg[b];
    }
    for (int i = 1; i <= n; ++i) cin >> c[i];
    int cc = 0;
    for (int i = 1; i <= n; ++i) if (!v[i] && deg[i] == 1) {
        dfs(i);
        ++cc;
    } 
    int cnt = 0;
    for (int i = 1; i <= n; ++i) if (!v[i]) ++cnt;
    if (cnt >= 2) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i) if (mark[i] >= cc - 1) return cout << i << endl, 0;
}

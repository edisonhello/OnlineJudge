#include <bits/stdc++.h>
using namespace std;

const int maxn = 3000 + 10;
vector<int> G[maxn];
bool go[maxn][maxn], v[maxn];

void dfs(int st, int now) {
    v[now] = true;
    go[st][now] = true;
    for (int u : G[noww]) {
        if (!v[u]) dfs(st, u);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n >> m >> q;
    while (m--) {
        int a, b; cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        memset(v, false, sizeof(v));
        dfs(i, i);
    }
}

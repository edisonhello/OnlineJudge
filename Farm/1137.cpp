#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int low[maxn], tin[maxn], stamp;
bool cut[maxn];

void init();
int dfs(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        init();
        int n, m; cin >> n >> m;
        while (m--) {
            int a, b; cin >> a >> b;
            G[a].push_back(b); G[b].push_back(a);
        }
        dfs(1, 0);
        int cnt = 0;
        for (int i = 1; i <= n; ++i) if (cut[i]) ++cnt;
        if (cnt == 0) cout << "0\n0" << endl;
        else {
            cout << cnt << endl;
            for (int i = 1; i <= n; ++i) if (cut[i]) cout << i << ' '; cout << endl;
        }
    }
    return 0;
}

void init() {
    fill(G, G + maxn, vector<int>());
    memset(low, 0, sizeof(low));
    memset(tin, 0, sizeof(tin));
    memset(cut, false, sizeof(cut));
    stamp = 0;
}

int dfs(int x, int fa) {
    tin[x] = low[x] = ++stamp;
    int ch = 0;
    for (int u : G[x]) {
        if (!tin[u]) {
            ++ch;
            int lowu = dfs(u, x);
            low[x] = min(low[x], lowu);
            if (low[u] >= tin[x]) cut[x] = true;
        } else if (tin[u] && u != fa) low[x] = min(low[x], tin[u]);
    }
    if (fa == 0 && ch == 1) cut[x] = false;
    return low[x];
}

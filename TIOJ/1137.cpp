#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
vector<int> G[maxn];
set<int> BCC[maxn];
int tin[maxn], ind, low[maxn], bcc;
stack<pair<int, int>> s;

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
        int ans = 0;
        for (int i = 1; i <= bcc; ++i) ans = max(ans, (int)BCC[i].size());
        cout << ans - 2 << endl;
    }
    return 0;
}

void init() {
    for (int i = 0; i < maxn; ++i) G[i].clear();
    memset(tin, 0, sizeof(tin)); memset(low, 0, sizeof(low));
    for (int i = 0; i < maxn; ++i) BCC[i].clear();
    ind = 0; bcc = 0;
    while (s.size()) s.pop();
}

int dfs(int x, int fa) {
    tin[x] = ++ind;
    low[x] = tin[x];
    for (int u : G[x]) {
        pair<int, int> p = make_pair(x, u);
        if (!tin[u]) {
            s.push(p);
            int lowu = dfs(u, x);
            low[x] = min(low[x], lowu);
            if (lowu >= tin[x]) {
                ++bcc;
                while (true) {
                    pair<int, int> e = s.top(); s.pop();
                    if (e.first == p.first && e.second == p.second) break;
                    BCC[bcc].insert(e.first); BCC[bcc].insert(e.second);
                }
            }
        } else if (tin[u] < tin[x] && u != fa) {
            low[x] = min(low[x], tin[u]);
            s.push(p);
        }
    }
    return low[x];
}

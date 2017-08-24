#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
bool v[maxn], used[maxn];

struct Dsu {
    int par[maxn], sz[maxn];
    void init() {
        for (int i = 0; i < maxn; ++i) par[i] = i, sz[i] = 1;
    }
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] < sz[y]) swap(x, y);
        par[y] = x;
        sz[x] += sz[y];
    }
    int size(int x) {
        return sz[find(x)];
    }
} dsu;

set<pair<int, int>> ed;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    dsu.init();
    while (m--) {
        int a, b; cin >> a >> b;
        if (ed.count(make_pair(b, a))) dsu.merge(a, b);
        ed.insert(make_pair(a, b));
        used[a] = used[b] = true;
    }
    int com = 0, ans = 0;
    for (int i = 1; i <= n; ++i) if (used[i]) {
        if (v[dsu.find(i)]) continue;
        ++com;
        v[dsu.find(i)] = true;
        if (dsu.size(i) > 1) ans += dsu.size(i);
    }
    ans += com - 1;
    cout << ans << endl;
    return 0;
}

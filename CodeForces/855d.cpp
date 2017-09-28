#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, lg = 20;
vector<pair<int, int>> G[maxn];
int dep[maxn], edge[2][lg][maxn], p[lg][maxn], tid[maxn], t;

void dfs(int now, int fa, int d, int e) {
    dep[now] = d; p[0][now] = fa; tid[now] = t;
    for (int i = 0; i < 2; ++i) edge[i][0][now] = (e == -1 || e == i);
    for (int i = 1; i < lg; ++i) {
        if ((1 << i) > d) break;
        p[i][now] = p[i - 1][p[i - 1][now]];
        for (int j = 0; j < 2; ++j) {
            edge[j][i][now] = edge[j][i - 1][now] && edge[j][i - 1][p[i - 1][now]];
        }
    }
    for (auto u : G[now]) if (u.first != fa) {
        dfs(u.first, now, d + 1, u.second);
    }
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    for (int i = 0; i < lg; ++i) {
        if ((dep[b] - dep[a]) >> i & 1) b = p[i][b];
    }
    if (a == b) return a;
    for (int i = lg - 1; i >= 0; --i) {
        if (p[i][a] != p[i][b]) {
            a = p[i][a]; b = p[i][b];
        }
        if (a == b) return a;
    }
    return p[0][a];
}

bool get(int a, int b, int e) {
    bool ret = true;
    for (int i = 0; i < lg; ++i) {
        if ((dep[a] - dep[b]) >> i & 1) {
            ret &= edge[e][i][a];
            a = p[i][a];
        }
    }
    if (dep[a] > dep[b]) ret &= edge[e][0][a];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> root;
    for (int i = 1; i <= n; ++i) {
        int p, t; cin >> p >> t;
        if (p == -1) root.push_back(i);
        else G[p].emplace_back(i, t);
    }
    for (int i : root) ++t, dfs(i, 0, 0, -1);
    int q; cin >> q; while (q--) {
        int t, a, b; cin >> t >> a >> b;
        if (tid[a] != tid[b]) {
            cout << "NO" << endl;
            continue;
        }
        int l = lca(a, b);
        if (t == 1) {
            if (l == a && get(b, l, 0) && a != b) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            if (get(a, l, 0) && get(b, l, 1) && l != b) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}

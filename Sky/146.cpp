#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

struct HeavyLightDecomp {
    vector<int> G[maxn];
    vector<int> tin, top, dep, maxson, sz, p;
    int n, t;
    void dfs(int now, int fa, int d) {
        dep[now] = d;
        maxson[now] = -1;
        sz[now] = 1;
        p[now] = fa;
        for (int u : G[now]) if (u != fa) {
            dfs(u, now, d + 1);
            sz[now] += sz[u];
            if (maxson[now] == -1 || sz[u] > sz[maxson[now]]) maxson[now] = u;
        }
    }
    void link(int now, int tp) {
        top[now] = tp;
        tin[now] = ++t;
        if (maxson[now] == -1) return;
        link(maxson[now], tp);
        for (int u : G[now]) if (u != p[now]) {
            if (u == maxson[now]) continue;
            link(u, u);
        }
    }
    HeavyLightDecomp(int n): n(n) {
        t = 0;
        tin.assign(n, 0); top.assign(n, 0); dep.assign(n, 0);
        maxson.assign(n, 0); sz.assign(n, 0); p.assign(n, 0);
    }
    void add_edge(int a, int b) {
        G[a].push_back(b);
        G[b].push_back(a);
    }
    void build() {
        dfs(0, -1, 0);
        link(0, 0);
    }
    int lca(int a, int b) {
        int ta = top[a], tb = top[b];
        while (ta != tb) {
            if (dep[ta] < dep[tb]) {
                swap(ta, tb); swap(a, b);
            }
            a = p[ta]; ta = top[a];
        }
        if (a == b) return a;
        return dep[a] < dep[b] ? a : b;
    }
    vector<pair<int, int>> get_path(int a, int b) {
        int ta = top[a], tb = top[b];
        vector<pair<int, int>> ret;
        while (ta != tb) {
            if (dep[ta] < dep[tb]) {
                swap(ta, tb); swap(a, b);
            }
            ret.push_back(make_pair(tin[ta], tin[a]));
            a = p[ta]; ta = top[a];
        }
        ret.push_back(make_pair(min(tin[a], tin[b]), max(tin[a], tin[b])));
        return ret;
    }
};

struct SegmentTree {
#define M ((L + R) >> 1)
    int val, tag;
    SegmentTree *lc, *rc;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        val = 0; tag = 0;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        val = lc->val + rc->val;
    }
    void push(int L, int R) {
        if (L == R || tag == 0) return;
        lc->val += (L - M + 1) * tag; lc->tag += tag;
        rc->val += (R - M) * tag; rc->tag += tag;
        tag = 0;
    }
    void modify(int L, int R, int l, int r, int v) {
        push(L, R);
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            val += (R - L + 1) * v; tag += v;
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        push(L, R);
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return val;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
#undef M 
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    HeavyLightDecomp hld(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a; --b;
        hld.add_edge(a, b);
    }
    hld.build(); st = new SegmentTree(1, n);
    while (m--) {
        char t; int a, b; cin >> t >> a >> b;
        --a; --b;
        vector<pair<int, int>> path = hld.get_path(a, b);
        int ans = 0;
        for (auto p : path) {
            if (p.first == p.second) continue;
            if (t == 'P') st->modify(1, n, p.first, p.second, 1);
            else ans += st->query(1, n, p.first, p.second);
        }
        if (t == 'Q') cout << ans << endl;
    }
    return 0;
}

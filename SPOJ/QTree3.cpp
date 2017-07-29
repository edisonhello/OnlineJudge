#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;

class HeavyLightDecomp {
    private:
        vector<int> G[maxn];
        int tin[maxn], top[maxn], dep[maxn], maxson[maxn], sz[maxn], p[maxn], rev[maxn << 1], n, clk;
        void dfs(int now, int fa, int d) {
            dep[now] = d;
            maxson[now] = -1;
            sz[now] = 1;
            p[now] = fa;
            tin[now] = ++clk;
            for (int u : G[now]) if (u != fa) {
                dfs(u, now, d + 1);
                sz[now] += sz[u];
                if (maxson[now] == -1 || sz[u] > sz[maxson[now]]) maxson[now] = u;
            }
        }
        void link(int now, int t) {
            top[now] = t;
            if (maxson[now] == -1) return;
            link(maxson[now], t);
            for (int u : G[now]) if (u != p[now]) {
                if (u == maxson[now]) continue;
                link(u, u);
            }
        }
        
    public:
        HeavyLightDecomp(int n): n(n) {
            clk = 0;
            memset(tin, 0, sizeof(tin)); memset(top, 0, sizeof(top)); memset(dep, 0, sizeof(dep));
            memset(maxson, 0, sizeof(maxson)); memset(sz, 0, sizeof(sz)); memset(p, 0, sizeof(p));
            memset(rev, 0, sizeof(rev));
        }
        void add_edge(int a, int b) {
            G[a].push_back(b);
            G[b].push_back(a);
        }
        void solve() {
            dfs(0, -1, 0);
            for (int i = 0; i < n; ++i) rev[tin[i]] = i;
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
        inline int timein(int vtx) { return tin[vtx]; }
        inline int size() { return clk; }
        inline int id(int t) { return rev[t]; }
};

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int pos = inf;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        pos = min(lc->pos, rc->pos);
    }
    void modify(int L, int R, int x) {
        if (L == R) {
            if (pos == x) pos = inf;
            else pos = x;
            return;
        }
        if (x <= M) lc->modify(L, M, x);
        else rc->modify(M + 1, R, x);
        pull();
    }
    int query(int L, int R, int l, int r) {
        if (L > r || l > R) return inf;
        if (L >= l && R <= r) return pos;
        return min(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
#undef M
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    HeavyLightDecomp hld = HeavyLightDecomp(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        --a; --b; hld.add_edge(a, b);
    }
    hld.solve();
    st = new SegmentTree(1, hld.size());
    while (q--) {
        int tp, a; cin >> tp >> a; --a;
        if (tp == 0) st->modify(1, hld.size(), hld.timein(a));
        else {
            vector<pair<int, int>> p = hld.get_path(0, a);
            int ans = inf;
            for (auto e : p) {
                int x = st->query(1, hld.size(), e.first, e.second);
                if (x != inf && ans == inf) ans = hld.id(x);
            }
            if (ans == inf) cout << "-1" << endl;
            else cout << ans + 1 << endl;
        }
    }
    return 0;
}

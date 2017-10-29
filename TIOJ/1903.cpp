#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 10;

namespace std {
    template <> struct hash<pair<int, int>> {
        size_t operator()(const pair<int, int> &e) const {
            return (e.first << 20) | e.second;
        }
    };
};

struct DisjointSet {
    int p[maxn], sz[maxn], n, cc;
    vector<pair<int*, int>> his;
    vector<int> sp;
    void init(int _n) {
        n = _n; cc = n;
        for (int i = 0; i < n; ++i) sz[i] = 1, p[i] = i;
        sp.clear(); his.clear();
    }
    void assign(int *k, int v) {
        his.emplace_back(k, *k);
        *k = v;
    }
    void save() {
        sp.push_back((int)his.size());
    }
    void undo() {
        int last = sp.back(); sp.pop_back();
        while (his.size() != last) {
            int *k, v;
            tie(k, v) = his.back(); his.pop_back();
            *k = v;
        }
    }
    int find(int x) {
        if (x == p[x]) return x;
        return find(p[x]);
    }
    void merge(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return;
        if (sz[x] > sz[y]) swap(x, y);
        assign(&sz[y], sz[x] + sz[y]);
        assign(&p[x], y);
        assign(&cc, cc - 1);
    }
} dsu;

unordered_map<pair<int, int>, pair<int, int>> cnt;
int n, m, q, ans[maxn];

struct SegmentTree {
#define M ((L + R) >> 1)
    static SegmentTree *ptr;
    static SegmentTree mem[2000000];
    vector<pair<int, int>> edge;
    SegmentTree *lc, *rc;
    SegmentTree() {}
    SegmentTree(int L, int R) {
        edge.clear();
        lc = rc = nullptr;
        if (L == R) return;
        lc = new (ptr++) SegmentTree(L, M); rc = new (ptr++) SegmentTree(M + 1, R);
    }
    void modify(int L, int R, int l, int r, pair<int, int> e) {
        if (L > r || l > R) return;
        if (L >= l && R <= r) return edge.push_back(e), void();
        lc->modify(L, M, l, r, e); rc->modify(M + 1, R, l, r, e);
    }
    void solve(int L, int R) {
        dsu.save();
        for (auto e : edge) dsu.merge(e.first, e.second);
        if (L == R) ans[L] = dsu.cc;
        else lc->solve(L, M), rc->solve(M + 1, R);
        dsu.undo();
    }
#undef M
} *st, *SegmentTree::ptr, SegmentTree::mem[2000000];

void add_edge(int a, int b, int t) {
    if (cnt.find(minmax(a, b)) == cnt.end()) cnt[minmax(a, b)] = make_pair(t, 1);
    else ++cnt[minmax(a, b)].second;
}

void del_edge(int a, int b, int t) {
    assert(cnt.find(minmax(a, b)) != cnt.end());
    --cnt[minmax(a, b)].second;
    if (cnt[minmax(a, b)].second > 0) return;
    st->modify(0, q, cnt[minmax(a, b)].first, t - 1, minmax(a, b));
    cnt.erase(minmax(a, b));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        cin >> n >> m >> q;
        cnt.clear(); dsu.init(n);
        SegmentTree::ptr = SegmentTree::mem;
        st = new (SegmentTree::ptr++) SegmentTree(0, q);
        for (int i = 0; i < m; ++i) {
            int a, b; cin >> a >> b;
            add_edge(a, b, 0);
        }
        for (int i = 1; i <= q; ++i) {
            char c; int a, b; cin >> c >> a >> b;
            if (c == 'N') add_edge(a, b, i);
            else del_edge(a, b, i);
        }
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            if (it->second.second == 0) continue;
            st->modify(0, q, it->second.first, q, it->first);
        }
        st->solve(0, q);
        for (int i = 1; i <= q; ++i) cout << ans[i] << '\n';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> G[maxn], T[maxn];
int tin[maxn], low[maxn], t, bccid[maxn], cnt, cid[maxn], a[maxn], b[maxn];
int dep[maxn], p[maxn], tp[maxn], sz[maxn], maxson[maxn], tid[maxn], tcnt, tsz[maxn];
stack<int> st;
bool cut[maxn];
set<pair<int, int>> edge;

void dfs1(int now, int fa) {
    low[now] = tin[now] = ++t;
    st.push(now);
    int c = 0;
    for (int u : G[now]) if (u != fa) {
        if (tin[u]) {
            low[now] = min(low[now], tin[u]);
            continue;
        }
        ++c;
        dfs1(u, now);
        low[now] = min(low[now], low[u]);
        if (low[u] > tin[now]) {
            ++cnt;
            while (true) {
                int v = st.top(); st.pop();
                bccid[v] = cnt;
                if (v == u) break;
            }
        }
    }
    if (c == 1 && fa == 0) cut[now] = false;
}

void add_edge(int a, int b) {
    // cout << a << " -> " << b << endl;
    T[a].push_back(b); T[b].push_back(a);
}

int dfs2(int now, int fa, int d) {
    tid[now] = tcnt;
    dep[now] = d;
    p[now] = fa;
    sz[now] = 1;
    maxson[now] = 0;
    // cout << "now = " << now << endl;
    // cout << "T[now].size() = " << T[now].size() << endl;
    for (int u : T[now]) if (u != fa && u != now) {
        // cout << "u = " << u << endl;
        dfs2(u, now, d + 1);
        sz[now] += sz[u];
        if (sz[u] > sz[maxson[now]]) maxson[now] = u;
    }
    return sz[now];
}

void link(int now, int head) {
    tp[now] = head;
    tin[now] = ++t;
    if (maxson[now] == 0) return;
    link(maxson[now], head);
    for (int u : T[now]) if (u != p[now] && u != now) {
        if (u == maxson[now]) continue;
        link(u, u);
    }
}

struct SegmentTree {
#define M ((L + R) >> 1)
    // static SegmentTree mem[800000];
    // static SegmentTree *ptr;
    SegmentTree *lc, *rc;
    int maxv, minv, tag;
    SegmentTree() {}
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        maxv = minv = 0;
        tag = 0;
        if (L == R) return;
        // lc = new (ptr++) SegmentTree(L, M); rc = new (ptr++) SegmentTree(M + 1, R);
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        maxv = max(lc->maxv, rc->maxv);
        minv = min(lc->minv, rc->minv);
    }
    void push() {
        if (!lc || tag == 0) return;
        lc->maxv = lc->minv = lc->tag = tag;
        rc->maxv = rc->minv = rc->tag = tag;
        tag = 0;
    }
    void modify(int L, int R, int l, int r, int v) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) return (maxv = minv = tag = v), void();
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    int maxquery(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return -2;
        if (L >= l && R <= r) return maxv;
        return max(lc->maxquery(L, M, l, r), rc->maxquery(M + 1, R, l, r));
    }
    int minquery(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return 2;
        if (L >= l && R <= r) return minv;
        return min(lc->minquery(L, M, l, r), rc->minquery(M + 1, R, l, r));
    }
    void debug(int L, int R) {
        if (L == R) return cout << "maxv = " << maxv << " minv = " << minv << endl, void();
        lc->debug(L, M); rc->debug(M + 1, R);
    }
#undef M
// } *sgt[maxn], SegmentTree::mem[800000], *SegmentTree::ptr = mem;
} *sgt[maxn];

int lca(int a, int b) {
    int ta = tp[a], tb = tp[b];
    while (ta != tb) {
        if (dep[ta] < dep[tb]) {
            swap(ta, tb);
            swap(a, b);
        }
        a = p[ta]; ta = tp[a];
    }
    return dep[a] < dep[b] ? a : b;
}

void imp() {
    cout << "No" << endl;
    exit(0);
}

void go(int a, int b, int id, int w) {
    // cout << "go a = " << a << " b = " << b << " w = " << w << endl;
    int ta = tp[a], tb = tp[b];
    while (ta != tb) {
        if (dep[ta] < dep[tb]) {
            swap(ta, tb);
            swap(a, b);
        }
        if (w == 1) {
            if (sgt[id]->minquery(1, cnt, tin[ta], tin[a]) == -1) imp();
            sgt[id]->modify(1, cnt, tin[ta], tin[a], 1);
        } else {
            if (sgt[id]->maxquery(1, cnt, tin[ta], tin[a]) == 1) imp();
            sgt[id]->modify(1, cnt, tin[ta], tin[a], -1);
        }
        a = p[ta]; ta = tp[a];
    }
    if (a == b) return; 
    if (dep[a] < dep[b]) swap(a, b);
    if (w == 1) {
        if (sgt[id]->minquery(1, cnt, tin[maxson[b]], tin[a]) == -1) imp();
        sgt[id]->modify(1, cnt, tin[maxson[b]], tin[a], 1);
    } else {
        if (sgt[id]->maxquery(1, cnt, tin[maxson[b]], tin[a]) == 1) imp();
        sgt[id]->modify(1, cnt, tin[maxson[b]], tin[a], -1);
    }
}


void solve(int a, int b) {
    if (tid[a] != tid[b]) imp();
    // cout << "solve a = " << a << " b = " << b << endl;
    int c = lca(a, b); 
    // cout << "lca = " << c << endl;
    go(a, c, tid[a], 1); 
    go(b, c, tid[a], -1);
    // sgt->debug(1, cnt);
}

struct dsu {
    int pa[maxn];
    void init() { for (int i = 0; i < maxn; ++i) pa[i] = i; }
    int find(int x) { return x == pa[x] ? x : pa[x] = find(pa[x]); }
    void merge(int x, int y) { pa[find(x)] = find(y); }
} dsu;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q; cin >> n >> m >> q;
    dsu.init();
    for (int i = 0; i < m; ++i) {
        cin >> a[i] >> b[i];
        if (edge.count(minmax(a[i], b[i]))) dsu.merge(a[i], b[i]);
        edge.insert(minmax(a[i], b[i]));
    }
    for (int i = 0; i < m; ++i) {
        G[dsu.find(a[i])].push_back(dsu.find(b[i]));
        G[dsu.find(b[i])].push_back(dsu.find(a[i]));
    }
    for (int i = 1; i <= n; ++i) if (!bccid[dsu.find(i)]) {
        dfs1(dsu.find(i), 0); 
        if (st.empty()) continue;
        ++cnt;
        while (st.size()) bccid[st.top()] = cnt, st.pop();
    }
    for (int i = 1; i <= n; ++i) {
        for (int j : G[dsu.find(i)]) add_edge(bccid[dsu.find(i)], bccid[dsu.find(j)]);
    }
    for (int i = 1; i <= cnt; ++i) {
        sort(T[i].begin(), T[i].end());
        T[i].resize(unique(T[i].begin(), T[i].end()) - T[i].begin());
    }
    // cout << "done initialize tree" << endl;
    memset(tin, 0, sizeof(tin));
    for (int i = 1; i <= cnt; ++i) if (!tin[i]) {
        t = 0; ++tcnt; tsz[tcnt] = dfs2(i, 0, 0); link(i, i);
    }
    // cout << "done building hld" << endl;
    for (int i = 1; i <= tcnt; ++i) {
        // sgt[i] = new (SegmentTree::ptr++) SegmentTree(1, tsz[i]);
        sgt[i] = new SegmentTree(1, tsz[i]);
    }
    while (q--) {
        int a, b; cin >> a >> b;
        a = bccid[dsu.find(a)]; b = bccid[dsu.find(b)];
        solve(a, b);
    }
    cout << "Yes" << endl;
    return 0;
}

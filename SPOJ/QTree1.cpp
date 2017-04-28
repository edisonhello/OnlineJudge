#include <bits/stdc++.h>
using namespace std;

const int maxn = 10000 + 5;
vector<pair<int, int>> G[maxn];
int tin[maxn], stamp, sz[maxn], maxson[maxn], link[maxn], dep[maxn], fa[maxn];

void init();
void dfs(int, int, int);
void decomp(int, int, int);
int query(int, int);

struct Seg {
    static Seg mem[maxn << 1];
    static int top;
    struct ptr {
        ptr() {}
        ptr(const Seg* s): c(s - mem) {}
        int c;
        Seg* operator->() { return mem + c; }
    } lc, rc;
    void* operator new(size_t x) { return mem + top++; }
    int Max;
    Seg() {
        lc = rc = NULL;
        Max = 0;
    }
    Seg(int L, int R) {
        lc = rc = NULL;
        Max = 0;
        if (L == R) return;
        int M = L + R >> 1;
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
    }
    int query(int L, int R, int l, int r) {
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return Max;
        int M = (L + R) >> 1;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
    void modify(int L, int R, int x, int v) {
        if (L == R) { Max = v; return; }
        int M = (L + R) >> 1;
        if (x <= M) lc->modify(L, M, x, v);
        else rc->modify(M + 1, R, x, v);
        pull();
    }
    void pull() {
        Max = max(lc->Max, rc->Max);
    }
} *st, Seg::mem[maxn << 1];

int Seg::top, n;
struct Edge { int from, to, w; };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        init();
        cin >> n;
        st = new Seg(1, n);
        vector<Edge> e;
        for (int i = 0; i < n - 1; ++i) {
            int a, b, c; cin >> a >> b >> c;
            G[a].push_back(make_pair(b, c));
            G[b].push_back(make_pair(a, c));
            e.push_back((Edge){ a, b, c });
        }
        dfs(1, 0, 0); 
        cerr << "dfs\n";
        decomp(1, 0, 1);
        cerr << "decomp\n";
        for (Edge ed : e) {
            if (tin[ed.from] > tin[ed.to]) swap(ed.from, ed.to);
            st->modify(1, n, tin[ed.to], ed.w);
        }
        string s;
        while (cin >> s) {
            if (s == "DONE") break;
            if (s == "CHANGE") {
                int i, ti; cin >> i >> ti;
                st->modify(1, n, tin[e[i - 1].to], ti);
            }
            if (s == "QUERY") {
                int a, b; cin >> a >> b;
                cout << query(a, b) << '\n';
            }
        }
    }
    return 0;
}

void init() {
    fill(G, G + maxn, vector<pair<int, int>>());
    memset(tin, 0, sizeof(tin));
    memset(sz, 0, sizeof(sz));
    memset(maxson, 0, sizeof(maxson));
    memset(dep, 0, sizeof(dep));
    stamp = 0; Seg::top = 0;
}

void dfs(int x, int f, int d) {
    fa[x] = f;
    tin[x] = ++stamp;
    sz[x] = 1;
    dep[x] = d;
    for (pair<int, int> edge : G[x]) if (edge.first != f) {
        dfs(edge.first, x, d + 1);
        if (sz[edge.first] > sz[maxson[x]]) maxson[x] = edge.first;
        sz[x] += sz[edge.first];
    }
}

void decomp(int x, int fa, int t) {
    cerr << "[decomp] x = " << x << '\n';
    link[x] = t;
    if (maxson[x]) decomp(maxson[x], x, t);
    for (pair<int, int> edge : G[x]) if (edge.first != fa) {
        if (edge.first == maxson[x]) continue;
        decomp(edge.first, x, edge.first);
    } 
}

int query(int a, int b) {
    int ta = link[a], tb = link[b];
    int ret = 0;
    while (ta != tb) {
        if (dep[a] > dep[b]) {
            swap(a, b);
            swap(ta, tb);
        }
        ret = max(ret, st->query(1, n, min(tin[tb], tin[b]), max(tin[b], tin[tb])));
        b = fa[tb]; tb = link[b];
    }
    ret = max(ret, st->query(1, n, min(tin[a], tin[b]), max(tin[a], tin[b])));
    return ret;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

inline int gtx() {
    const int N = 1048576;
    static char buffer[N];
    static char *p = buffer, *end = buffer;
    if (p == end) {
        if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
        p = buffer;
    }
    return *p++;
}

template <typename T>
inline bool rit(T& x) {
    char __c = 0; bool flag = false;
    while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
    __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
    while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
    if (flag) x = -x;
    return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

class HeavyLightDecomp {
    private:
        vector<int> G[maxn];
        int tin[maxn], top[maxn], dep[maxn], maxson[maxn], sz[maxn], p[maxn], rev[maxn << 1], n, clk;
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
        void link(int now, int t) {
            top[now] = t;
            tin[now] = ++clk;
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
        inline int id(int t) { return rev[t]; }
};

vector<int> p[maxn];

vector<int> merge(const vector<int>& a, const vector<int>& b) {
    vector<int> tmp, ret;
    for (int i : a) tmp.push_back(i);
    for (int i : b) tmp.push_back(i);
    sort(tmp.begin(), tmp.end()); tmp.resize(unique(tmp.begin(), tmp.end()) - tmp.begin());
    for (int i = 0; i < min(10, (int)tmp.size()); ++i) ret.push_back(tmp[i]);
    return ret;
}

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    vector<int> vec;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        vec.clear();
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }    
    void pull() {
        vec = merge(lc->vec, rc->vec);
    }
    void modify(int L, int R, int x, const vector<int>& p) {
        if (L == R) {
            vec = merge(vec, p);
            return;
        }
        if (x <= M) lc->modify(L, M, x, p);
        else rc->modify(M + 1, R, x, p);
        pull();
    }
    vector<int> query(int L, int R, int l, int r) {
        if (L > r || l > R) return vector<int>();
        if (L >= l && R <= r) return vec;
        return merge(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
#undef M
} *st;

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, q; rit(n, m, q);
    HeavyLightDecomp hld(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b; rit(a, b); --a; --b;
        hld.add_edge(a, b);
    }
    hld.solve();
    for (int i = 1; i <= m; ++i) {
        int c; rit(c); --c;
        p[c].push_back(i);
    }
    st = new SegmentTree(1, n);
    for (int i = 0; i < n; ++i) st->modify(1, n, hld.timein(i), p[i]);
    while (q--) {
        int a, b, sz; rit(a, b, sz); --a; --b;
        vector<pair<int, int>> pt = hld.get_path(a, b);
        vector<int> ans;
        for (auto i : pt) {
            ans = merge(ans, st->query(1, n, i.first, i.second));
        }
        printf("%d ", min((int)ans.size(), sz));
        for (int i = 0; i < min((int)ans.size(), sz); ++i) printf("%d ", ans[i]); printf("\n");
    }
    return 0;
}

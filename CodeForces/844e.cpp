#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
vector<int> G[maxn], vec;
int dep[maxn], n, sz[maxn], p[maxn], tin[maxn], tout[maxn], t;
vector<pair<pair<int, int>, int>> curans;

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int dep, tag;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        dep = 0;
        tag = 0;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        dep = max(lc->dep, rc->dep);
    }
    ~SegmentTree() {
        if (lc) delete lc;
        if (rc) delete rc;
    }
    void modify(int L, int R, int l, int r, int v) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            dep += v;
            tag += v;
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return -1;
        if (L >= l && R <= r) return dep;
        return max(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
    void push() {
        if (!lc || tag == 0) return;
        lc->dep += tag; lc->tag += tag;
        rc->dep += tag; rc->tag += tag;
        tag = 0;
    }
} *st;

void dfs(int now, int fa, int d) {
    dep[now] = d;
    sz[now] = 1;
    p[now] = fa;
    tin[now] = ++t;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, d + 1);
        sz[now] += sz[u];
    }
    tout[now] = t;
}

bool check(int maxdep) {
    // cout << "checking maxdep = " << maxdep << endl;
    vector<pair<pair<int, int>, int>> ans;
    st = new SegmentTree(1, n);
    for (int i = 1; i <= n; ++i) st->modify(1, n, tin[i], tin[i], dep[i]);
    for (int i : vec) if (st->query(1, n, tin[i], tout[i]) > maxdep) {
        // cout << "i = " << i << endl;
        if (sz[i] > n - sz[i]) if (p[i] && p[i] != 1) {
            ans.push_back(make_pair(make_pair(i, p[i]), 1));
            st->modify(1, n, tin[i], tout[i], -1);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (st->query(1, n, tin[i], tin[i]) > maxdep) {
            delete st;
            return false;
        }
    }
    curans = ans;
    delete st;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b); G[b].emplace_back(a);
    }
    for (int i = 1; i <= n; ++i) vec.emplace_back(i);
    sort(vec.begin(), vec.end(), [](const int &a, const int& b) { return dep[a] > dep[b]; });
    dfs(1, 0, 0);
    int d = 1, ans = n; while (d <= n) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << curans.size() << endl;
    for (auto i : curans) {
        cout << i.first.first << ' ' << i.first.second << ' ' << i.second << endl;
    }
    return 0;
}

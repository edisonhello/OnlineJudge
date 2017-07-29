#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int dep[maxn], maxson[maxn], top[maxn], p[maxn], sz[maxn], tin[maxn], t;

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    int sum, tag;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        sum = 0; tag = -1;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
    void push(int L, int R) {
        if (L == R || tag == -1) return;
        lc->sum = (M - L + 1) * tag; lc->tag = tag;
        rc->sum = (R - M) * tag; rc->tag = tag;
        tag = -1;
    }
    void modify(int L, int R, int l, int r, int v) {
        push(L, R);
        if (L > r || l > R)return;
        if (L >= l && R <= r) {
            sum = (R - L + 1) * v; tag = v;
            return;
        }
        lc->modify(L, M, l, r, v); rc->modify(M + 1, R, l, r, v);
        pull();
    }
    int query(int L, int R, int l, int r) {
        push(L, R);
        if (L > r || l > R)return 0;
        if (L >= l && R <= r)return sum;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
} *st;

void get_size(int now, int fa, int d) {
    sz[now] = 1; maxson[now] = -1; dep[now]  =d; p[now] = fa;
    for (int u : G[now]) if (u != fa) {
        get_size(u, now, d + 1);
        sz[now] += sz[u];
        if (maxson[now] == -1 || sz[u] > sz[maxson[now]]) {
            maxson[now] = u;
        }
    }
}

void dfs(int now, int tp) {
    tin[now] = ++t;
    top[now] = tp;
    if (maxson[now] == -1) return;
    dfs(maxson[now], tp);
    for (int u : G[now]) if (u != p[now]) {
        if (u == maxson[now]) continue;
        dfs(u, u);
    }
}

int go(int a, int b, int tp) {
    int ans = 0;
    int ta = top[a], tb = top[b];
    while (ta != tb) {
        if (dep[ta] < dep[tb]) {
            swap(ta, tb); swap(a, b);
        }
        ans += st->query(1, t, tin[ta], tin[a]);
        if (tp != -1) st->modify(1, t, tin[ta], tin[a], tp);
        a = p[ta]; ta = top[a];
    }
    ans += st->query(1, t, min(tin[a], tin[b]), max(tin[a], tin[b]));
    if (tp != -1) st->modify(1, t, min(tin[a], tin[b]), max(tin[a], tin[b]), tp);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 2; i <= n; ++i) {
        int p; cin >> p;
        G[p].push_back(i); G[i].push_back(p);
    }
    get_size(1, 0, 0);  dfs(1, 1);
    st = new SegmentTree(1, t);
    while (q--) {
        vector<int> vec(3);
        for (int i = 0; i < 3; ++i) cin >> vec[i];
        sort(vec.begin(), vec.end());
        int ans = 0;
        do {
            go(vec[1], vec[0], 1); ans = max(ans, go(vec[2], vec[0], -1)); go(vec[1], vec[0], 0);
        } while (next_permutation(vec.begin(), vec.end()));
        cout << ans << endl;
    }
    return 0;
}

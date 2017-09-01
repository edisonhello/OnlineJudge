#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, sq = 320;
pair<int, int> data[sq][maxn];
int a[maxn], n, lb[sq], rb[sq], pos[maxn];

pair<int, int> merge(const pair<int, int>& a, const pair<int, int>& b) {
    return make_pair(min(a.first, b.first), max(a.second, b.second));
}

struct SegmentTree {
#define M ((L + R) >> 1)
    SegmentTree *lc, *rc;
    pair<int, int> val;
    SegmentTree(int L, int R) {
        lc = rc = nullptr;
        val = make_pair(n + 1, 0);
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
        pull();
    }
    void pull() {
        val = merge(lc->val, rc->val);
    }
    void modify(int L, int R, int x, pair<int, int> v) {
        if (L == R) { val = v; return; }
        if (x <= M) lc->modify(L, M, x, v);
        else rc->modify(M + 1, R, x, v);
        pull();
    }
    pair<int, int> query(int L, int R, int l, int r) {
        if (L > r || l > R) return make_pair(n + 1, 0);
        if (L >= l && R <= r) return val;
        return merge(lc->query(L, M, l, r), rc->query(M + 1, R, l, r));
    }
} *st[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int blk = 0;
    for (int i = 0; i < sq; ++i) for (int j = 0; j < maxn; ++j) data[i][j] = make_pair(n + 1, 0);
    for (int i = 1; i <= n; ) {
        int j = 0;
        ++blk;
        lb[blk] = i;
        for (int j = 0; i + j <= n && j < sq; ++j) {
            data[blk][a[i + j]].second = max(data[blk][a[i + j]].second, i + j);
            data[blk][a[i + j]].first = min(data[blk][a[i + j]].first, i + j);
            pos[i + j] = blk;
        }
        i += j;
        rb[blk] = i - 1;
    }
    for (int i = 1; i <= n; ++i) st[i] = new SegmentTree(1, blk);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= blk; ++j) st[i]->modify(1, blk, j, data[j][i]);
    }
    while (m--) {
        int t; cin >> t;
        if (t == 1) {
            int p, x; cin >> p >> x;

        } else {
            int l, r; cin >> l >> r;
            pair<int, int> q = st[]
        }
    }
}

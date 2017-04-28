#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int b[maxn], n;

struct Seg {
    Seg *lc, *rc;
    int sum;
#define M ((L + R) >> 1)
    Seg(int L, int R) {
        lc = rc = nullptr;
        sum = 0;
        if (L == R) return;
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
    }
    Seg(Seg* t) {
        lc = t->lc; rc = t->rc;
        sum = t->sum;
    }
    void pull() {
        sum = lc->sum + rc->sum;
    }
    int query(int L, int R, int l, int r) {
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) return sum;
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
    Seg* modify(int L, int R, int x) {
        Seg* ret = new Seg(this);
        if (L == R) { ++ret->sum; return ret; }
        if (x <= M) ret->lc = lc->modify(L, M, x);
        else ret->rc = rc->modify(M + 1, R, x);
        ret->pull();
        return ret;
    }
#undef M
} *st[maxn];

bool check(int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m; cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    st[0] = new Seg(1, n);
    for (int i = 1; i <= n; ++i) st[i] = st[i - 1]->modify(1, n, b[i]);
    for (int i = 0; i < m; ++i) {
        int p, k; cin >> p >> k; ++p;
        int d = 1; while (d <= n) d <<= 1;
        int ans = n;
        while (d >>= 1) if (ans - d >= 0) if (check(ans - d, p, k)) ans -= d;
        cout << ans << '\n';
    }
    return 0;
}

bool check(int x, int p, int k) {
    int l = max(p - x, 1), r = min(p + x, n);
    return st[r]->query(1, n, 1, x) - st[l - 1]->query(1, n, 1, x) >= k;
}

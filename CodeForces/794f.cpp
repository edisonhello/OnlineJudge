#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, digit = 10;
int a[maxn];

struct Seg {
    Seg *lc, *rc;
    int tag[digit];
    long long sum[digit];
#define M ((L + R) >> 1)
    Seg(int L, int R) {
        lc = rc = nullptr;
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < digit; ++i) tag[i] = i;
        if (L == R) {
            int tmp = a[L];
            long long k = 1;
            while (tmp) {
                sum[tmp % digit] += k;
                k *= (long long)digit; tmp /= digit;
            }
            return;
        }
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
        pull();
    }
    void pull() {
        for (int i = 0; i < digit; ++i) sum[i] = lc->sum[i] + rc->sum[i];
    }
    void push() {
        if (!lc) return;
        for (int i = 0; i < digit; ++i) {
            if (tag[i] == i) continue;
            lc->sum[tag[i]] += lc->sum[i]; lc->sum[i] = 0;
            rc->sum[tag[i]] += rc->sum[i]; rc->sum[i] = 0;
            lc->tag[i] = tag[i];
            rc->tag[i] = tag[i];

        }
        for (int i = 0; i < digit; ++i) tag[i] = i;
    }
    void modify(int L, int R, int l, int r, int x, int y) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            sum[y] += sum[x];
            sum[x] = 0;
            tag[x] = y;
            return;
        }
        lc->modify(L, M, l, r, x, y); rc->modify(M + 1, R, l, r, x, y);
        pull();
    }
    long long query(int L, int R, int l, int r) {
        push();
        if (L > r || l > R) return 0;
        if (L >= l && R <= r) {
            long long ret = 0;
            for (int i = 0; i < digit; ++i) ret += (long long)i * sum[i];
            return ret;
        }
        return lc->query(L, M, l, r) + rc->query(M + 1, R, l, r);
    }
#undef M
} *seg;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    seg = new Seg(1, n);
    while (q--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int l, r, x, y; cin >> l >> r >> x >> y;
            if (x == y) continue;
            seg->modify(1, n, l, r, x, y);
        } else {
            int l, r; cin >> l >> r;
            cout << seg->query(1, n, l, r) << '\n';
        }
    }
    return 0;
}

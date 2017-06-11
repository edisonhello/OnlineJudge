#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 10;

struct Seg {
    Seg *lc, *rc;
    int ub, lb;
#define M ((L + R) >> 1)
    Seg(int L, int R) {
        lc = rc = nullptr;
        ub = 5e5 + 1, lb = 0;
        if (L == R) return;
        lc = new Seg(L, M); rc = new Seg(M + 1, R);
    }
    void modify(int L, int R, int l, int r, int op, int h) {
        if (L > r || l > R) return;
        push();
        if (L >= l && R <= r) {
            if (op == 1) lb = max(lb, h);
            else ub = min(ub, h);
            return;
        }
        lc->modify(L, M, l, r, op, h); rc->modify(M + 1, R, l, r, op, h);
    }
    void print(int L, int R) {
        push();
        if (L == R) {
            cout << min(lb, ub) << endl;
            return;
        }
        lc->print(L, M); rc->print(M + 1, R);
    }
    void push() {
        if (!lc) return;
        lc->ub = min(lc->ub, ub); lc->lb = max(lc->lb, lb);
        rc->ub = min(rc->ub, ub); rc->lb = max(rc->lb, lb);
    }
#undef M
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    st = new Seg(0, n - 1);
    while (m--) {
        int op, l, r, h; cin >> op >> l >> r >> h;
        st->modify(0, n - 1, l, r, op, h);
    }
    st->print(0, n - 1);
    return 0;
}

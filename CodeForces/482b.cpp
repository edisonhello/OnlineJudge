#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, bit = 30;
vector<int> ans;

void no() {
    cout << "NO" << endl;
    exit(0);
}

struct SegmentTree {
#define M ((L + R) >> 1)
    int val[bit], tag[bit];
    SegmentTree *lc, *rc;
    SegmentTree(int L, int R) {
        memset(val, -1, sizeof(val)); memset(tag, -1, sizeof(tag));
        lc = rc = nullptr;
        if (L == R) return;
        lc = new SegmentTree(L, M); rc = new SegmentTree(M + 1, R);
    }
    int merge(int a, int b) {
        if (a == -1 || b == -1) return -1;
        if (a == 0 || b == 0) return 0;
        return 1;
    }
    void pull() {
        for (int i = 0; i < bit; ++i) val[i] = merge(lc->val[i], rc->val[i]);
    }
    vector<bool> modify(int L, int R, int l, int r, vector<int> x) {
        push();
        if (L > r || l > R) return;
        if (L >= l && R <= r) {
            vector<bool> ret(bit, false);
            for (int i = 0; i < bit; ++i) {
                if (x[i] == 1) {
                    if (val[i] == 0) no();
                    val[i] = 1; tag[i] = 1;
                    ret[i] = true;
                } else if (x[i] == 0) {
                    if (val[i] == 1) ret[i] = false;;
                    else val[i] = 0, tag[i] = 0, ret[i] = true;
                }
            }
            return ret;
        }
        vector<bool> res = lc->modify(L, M, l, r, x);
        vector<int> rec;
        for (int i = 0; i < bit; ++i) {
            if (res[i]) {
                if (x[i] == 0) rec.push_back(-1);
                else if (x[i] == 0) rec.push_back(1);
                else rec.push_back(-1);
            } else {
                if (x[i] == 1) no();
                else if (x[i] == 0) rec.push_back(0);
                else rec.push_back(-1);
            }
        }
        vector<bool> res2 = rc->modify(M + 1, R, l, r, rec);
        vector<bool> ret;
        for (int i = 0; i < bit; ++i) {
            if (x[i] == 1) {
                if (!res2[i] || !res[i]) ret.push_back(false);
                else ret.push_back(true);
            } else if (x[i] == 0) {
                if (res2[i] || res[i]) ret.push_back(true);
                else ret.push_back(false);
            } else ret.push_back(true);
        }
        pull();
        return ret;
    }
    void push() {
        if (!lc) return;
        for (int i = 0; i < bit; ++i) if (tag[i] != -1) {
            if (tag[i] == 1) {
                if (lc->val[i] == 0 || rc->val[i] == 0) no();
                lc->val[i] = 1; lc->tag[i] = 1;
                rc->val[i] = 1; rc->tag[i] = 1;
            } else {
                if (lc->val[i] == 1 || rc->val[i] == 1) no();
                lc->tag[i] = 0; lc->val[i] = 0;
                rc->tag[i] = 0; rc->val[i] = 0;
            }
            tag[i] = -1;
        }
    }
    void print(int L, int R) {
        push();
        if (L == R) {
            int ret = 0;
            for (int i = 0; i < bit; ++i) {
                if (val[i] == 1) ret += (1 << i);
            }
            ans.push_back(ret);
            return;
        }
        lc->print(L, M); rc->print(M + 1, R);
    }
#undef M
} *st;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    st = new SegmentTree(1, n);
    while (m--) {
        int l, r, q; cin >> l >> r >> q;
        vector<int> mod;
        for (int i = 0; i < bit; ++i) mod.push_back(q >> i & 1);
        st->modify(1, n, l, r, mod);
    }
    st->print(1, n);
    cout << "YES" << endl;
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}

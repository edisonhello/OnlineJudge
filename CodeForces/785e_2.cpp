#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, mem = 1e8 + 10;
int lc[mem], rc[mem], cnt[mem], ptr, a[maxn], n, q;

#define M ((L + R) >> 1)

void pull(int id) {
    cnt[id] = cnt[lc[id]] + cnt[rc[id]];
}

void build(int id, int L, int R) {
    cnt[id] = 0;
    if (L == R) return;
    build(lc[id] = ++ptr, L, M); build(rc[id] = ++ptr, M + 1, R);
    pull(id);
}

int modify(int id, int L, int R, int x, int v) {
    int ret = ++ptr;
    cnt[ret] = cnt[id]; lc[ret] = lc[id]; rc[ret] = rc[id];
    if (L == R) {
        cnt[ret] += v;
        return ret;
    }
    if (x <= M) lc[ret] = modify(lc[id], L, M, x, v);
    else rc[ret] = modify(rc[id], M + 1, R, x, v);
    pull(ret);
    return ret;
}

int query(int id, int L, int R, int l, int r) {
    if (L > r || l > R) return 0;
    if (L >= l && R <= r) return cnt[id];
    return query(lc[id], L, M, l, r) + query(rc[id], M + 1, R, l, r);
}

#undef M

struct Fenwick {
    int st[maxn];
    void init() {
        st[0] = ++ptr;
        build(st[0], 1, n);
        for (int i = 1; i <= n; ++i) st[i] = st[0];
    }
    inline int lowbit(int x) {
        return x & -x;
    }
    void add(int id, int x, int v) {
        for (int i = id; i < maxn; i += lowbit(i)) st[i] = modify(st[i], 1, n, x, v);
    }
    vector<int> qry(int x) {
        vector<int> ret;
        for (int i = x; i; i -= lowbit(i)) ret.push_back(st[i]);
        return ret;
    }
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; ++i) a[i] = i;
    bit.init();
    for (int i = 1; i <= n; ++i) bit.add(i, a[i], 1);
    long long ans = 0;
    while (q--) {
        int l, r; cin >> l >> r;
        if (l > r) swap(l, r);
        if (l == r) {
            cout << ans << endl;
            continue;
        }
        bit.add(l, a[l], -1); bit.add(r, a[r], -1);
        long long cur = 0;
        vector<int> res1 = bit.qry(l), res2 = bit.qry(n);
        for (int i = 0; i < res1.size(); ++i) cur += query(res1[i], 1, n, a[l] + 1, n);
        for (int i = 0; i < res2.size(); ++i) cur += query(res2[i], 1, n, 1, a[l] - 1);
        for (int i = 0; i < res1.size(); ++i) cur -= query(res1[i], 1, n, 1, a[l] - 1);
        res1 = bit.qry(r);
        for (int i = 0; i < res1.size(); ++i) cur += query(res1[i], 1, n, a[r] + 1, n);
        for (int i = 0; i < res2.size(); ++i) cur += query(res2[i], 1, n, 1, a[r] - 1);
        for (int i = 0; i < res1.size(); ++i) cur -= query(res1[i], 1, n, 1, a[r] - 1);
        res1 = bit.qry(l);
        for (int i = 0; i < res1.size(); ++i) cur -= query(res1[i], 1, n, a[r] + 1, n);
        for (int i = 0; i < res2.size(); ++i) cur -= query(res2[i], 1, n, 1, a[r] - 1);
        for (int i = 0; i < res1.size(); ++i) cur += query(res1[i], 1, n, 1, a[r] - 1);
        res1 = bit.qry(r);
        for (int i = 0; i < res1.size(); ++i) cur -= query(res1[i], 1, n, a[l] + 1, n);
        for (int i = 0; i < res2.size(); ++i) cur -= query(res2[i], 1, n, 1, a[l] - 1);
        for (int i = 0; i < res1.size(); ++i) cur += query(res1[i], 1, n, 1, a[l] - 1);
        bit.add(l, a[r], 1), bit.add(r, a[l], 1);
        if (a[r] > a[l]) ++ans;
        else --ans;
        swap(a[l], a[r]);
        ans -= cur;
        cout << ans << endl;
    }
    return 0;
}

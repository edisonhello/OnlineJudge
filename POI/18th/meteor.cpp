#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10, inf = 1e9 + 1;
int a[maxn], p[maxn], ans[maxn], n, m, tmp[maxn];
vector<int> orb[maxn];

struct fenwick {
    int arr[maxn];
    void init() {
        memset(arr, 0, sizeof(arr));
    }
    inline int lowbit(int x) {
        return x & -x;
    }
    int add(int x, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) arr[i] += v;
    }
    int qry(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret += arr[i];
        return ret;
    }
} bit;

struct query {
    int t, l, r, v;
    query(int a, int b, int c, int d) {
        t = a; l = b; r = c; v = d;
    }
};

void modify(int l, int r, int v) {
    if (l <= r) bit.add(l, v), bit.add(r + 1, -v);
    else bit.add(1, v), bit.add(r + 1, -v), bit.add(l, v), bit.add(m + 1, -v);
}

void bs(vector<query>& qry, vector<int>& ask, int l, int r) {
    if (l > r) return;
    if (ask.size() == 0) return;
    if (qry.size() == 0) return;
    if (l == r) {
        for (int i : ask) ans[i] = l;
        return;
    }
    int m = (l + r) >> 1;
    for (auto i : qry) {
        if (i.t <= m) modify(i.l, i.r, i.v);
    }
    for (int i : ask) {
        tmp[i] = 0;
        for (int j : orb[i]) {
            tmp[i] += bit.qry(j);
            if (tmp[i] > p[i]) break;
        }
    }
    for (auto i : qry) {
        if (i.t <= m) modify(i.l, i.r, -i.v);
    }
    vector<query> ql, qr;
    vector<int> askl, askr;
    for (int i : ask) {
        if (p[i] - tmp[i] > 0) p[i] -= tmp[i], askr.push_back(i);
        else askl.push_back(i);
    }
    for (auto i : qry) {
        if (i.t <= m) ql.push_back(i);
        else qr.push_back(i);
    }
    bs(ql, askl, l, m); bs(qr, askr, m + 1, r);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int o; cin >> o;
        orb[o].push_back(i);
    }
    for (int i = 1; i <= n; ++i) cin >> p[i];
    vector<query> qry;
    vector<int> ask;
    int k; cin >> k;
    for (int i = 1; i <= k; ++i) {
        int l, r, v; cin >> l >> r >> v;
        qry.push_back(query(i, l, r, v));
    }
    for (int i = 1; i <= n; ++i) ask.push_back(i);
    memset(ans, -1, sizeof(ans));
    qry.push_back(query(k + 1, 1, m, inf));
    bs(qry, ask, 1, k + 1);
    for (int i = 1; i <= n; ++i) {
        if (ans[i] == k + 1 || ans[i] == -1) cout << "NIE" << endl;
        else cout << ans[i] << endl;
    }
    return 0;
}

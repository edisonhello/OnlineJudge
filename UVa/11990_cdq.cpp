#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], b[maxn], pos[maxn], ans[maxn];
bool v[maxn];

struct query {
    int x, y, t, id, ans;
    query(int a, int b, int c, int d): x(a), y(b), t(c), id(d) {
        ans = 0;
    }
};

struct fenwick {
    int arr[maxn];
    void init() {
        memset(arr, 0, sizeof(arr));
    }
    inline int lowbit(int x) {
        return x & -x;
    }
    int qry(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret += arr[i];
        return ret;
    }
    void add(int x, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) arr[i] += v;
    }
} bit;

void cdq1(vector<query>& qry, int l, int r) {
    if (qry.size() == 0) return;
    if (l == r) return;
    int m = (l + r) >> 1;
    for (auto i : qry) {
        if (i.t <= m) bit.add(i.y, 1);
        if (i.t > m && i.id != -1) ans[i.id] += bit.qry(maxn - 1) - bit.qry(i.y);
    }
    for (auto i : qry) {
        if (i.t <= m) bit.add(i.y, -1);
    }
    vector<query> ql, qr;
    for (auto i : qry) {
        if (i.t <= m) ql.push_back(i);
        else qr.push_back(i);
    }
    cdq1(ql, l, m); cdq1(qr, m + 1, r);
}

void cdq2(vector<query>& qry, int l, int r) {
    if (qry.size() == 0) return;
    if (l == r) return;
    int m = (l + r) >> 1;
    for (auto i : qry) {
        if (i.t <= m) bit.add(i.y, 1);
        if (i.t > m && i.id != -1) ans[i.id] += bit.qry(i.y - 1);
    }
    for (auto i : qry) {
        if (i.t <= m) bit.add(i.y, -1);
    }
    vector<query> ql, qr;
    for (auto i : qry) {
        if (i.t <= m) ql.push_back(i);
        else qr.push_back(i);
    }
    cdq2(ql, l, m); cdq2(qr, m + 1, r);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; while (cin >> n >> m) {
        memset(v, false, sizeof(v));
        for (int i = 1; i <= n; ++i) cin >> a[i], pos[a[i]] = i;
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
            v[b[i]] = true;
        }
        vector<query> qry;
        int ind = 1;
        for (int i = 1; i <= n; ++i) if (!v[i]) {
            qry.push_back(query(pos[i], i, ind, ind));
            ++ind;
        }
        vector<int> opt;
        for (int i = m - 1; i >= 0; --i) {
            qry.push_back(query(pos[b[i]], b[i], ind, ind));
            opt.push_back(ind); ++ind;
        }
        sort(qry.begin(), qry.end(), [](const query& a, const query& b) {
            return a.x < b.x;
        });
        memset(ans, 0, sizeof(ans));
        bit.init();
        cdq1(qry, 1, n);
        sort(qry.begin(), qry.end(), [](const query& a, const query& b) {
            return a.x > b.x;
        });
        bit.init();
        cdq2(qry, 1, n);
        for (int i = 1; i <= n; ++i) ans[i] += ans[i - 1];
        for (int i = m - 1; i >= 0; --i) cout << ans[opt[i]] << endl;
    }
    cout << endl;
    return 0;
}


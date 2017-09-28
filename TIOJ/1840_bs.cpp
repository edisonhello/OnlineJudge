#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10, maxq = 1e4 + 10;
int ans[maxq], a[maxn], tmp[maxq + maxn];

struct query {
    int id, t, l, r, k, sum;
    query(int a, int b, int c, int d, int e, int f) {
        id = a; t = b; 
        l = c; r = d;
        k = e; sum = f;
    }
    query operator+(const int& a) const {
        return query(id, t, l, r, k, sum + a);
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
    void add(int x, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) arr[i] += v;
    }
    int qry(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret += arr[i];
        return ret;
    }
} bit;

void bs(const vector<query>& qry, int l, int r) {
    int m = (l + r) >> 1;
    if (qry.size() == 0) return;
    if (l == r) {
        for (auto i : qry) {
            if (i.id >= 0) ans[i.id] = l;
        }
        return;
    }
    for (int i = 0; i < qry.size(); ++i) {
        if (qry[i].t == 2) {
            if (qry[i].r <= m) bit.add(qry[i].l, 1);
        }
        if (qry[i].t == 3) {
            if (qry[i].r <= m) bit.add(qry[i].l, -1);
        }
        if (qry[i].t == 1) {
            tmp[i] = bit.qry(qry[i].r) - bit.qry(qry[i].l - 1);
        }
    }
    for (int i = 0; i < qry.size(); ++i) {
        if (qry[i].t == 2) {
            if (qry[i].r <= m) bit.add(qry[i].l, -1);
        }
        if (qry[i].t == 3) {
            if (qry[i].r <= m) bit.add(qry[i].l, 1);
        }
    }
    vector<query> ql, qr;
    for (int i = 0; i < qry.size(); ++i) {
        if (qry[i].t == 1) {
            if (qry[i].sum + tmp[i] > qry[i].k - 1) ql.push_back(qry[i]);
            else qr.push_back(qry[i] + tmp[i]);
        } else {
            if (qry[i].r <= m) ql.push_back(qry[i]);
            else qr.push_back(qry[i]);
        }
    }
    bs(ql, l, m);
    bs(qr, m + 1, r);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, q; cin >> n >> q;
        vector<query> qry;
        vector<int> vec;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            qry.push_back(query(-1, 2, i, a[i], 0, 0));
            vec.push_back(a[i]);
        }
        int ind = 0;
        for (int i = 0; i < q; ++i) {
            int t; cin >> t;
            if (t == 1) {
                int l, r, k; cin >> l >> r >> k;
                qry.push_back(query(ind++, 1, l, r, k, 0));
            }
            if (t == 2) {
                int c, v; cin >> c >> v;
                vec.push_back(v);
                qry.push_back(query(-1, 3, c, a[c], 0, 0));
                qry.push_back(query(-1, 2, c, v, 0, 0));
                a[c] = v;
            }
            if (t == 3) {
                int a, b; cin >> a >> b;
                ans[ind++] = -1;
            }
        }
        sort(vec.begin(), vec.end()); vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
        for (auto& i : qry) {
            if (i.t == 2 || i.t == 3) i.r = lower_bound(vec.begin(), vec.end(), i.r) - vec.begin();
        }
        bit.init();
        bs(qry, 0, vec.size() - 1);
        for (int i = 0; i < ind; ++i) {
            if (ans[i] == -1) cout << "7122" << endl;
            else cout << vec[ans[i]] << endl;
        }
    }
    return 0;
}

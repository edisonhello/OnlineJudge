#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], ans[maxn];

struct operation {
    int x, y, t, id;
    bool operator<(const operation &rhs) const {
        return x < rhs.x;
    }
};

struct fenwick {
    int data[maxn];
    void init() { memset(data, 0, sizeof(data)); }
    void add(int x, int v) { for (; x < maxn; x += x & -x) data[x] += v; }
    int qry(int x, int ret = 0) { for (; x; x -= x & -x) ret += data[x]; return ret; }
} bit;

void cdq(const vector<operation> &op, int l, int r) {
    cout << "l = " << l << " r = " << r << endl;
    if (op.size() == 0) return;
    if (l >= r) return;
    int m = (l + r) >> 1;
    for (auto o : op) {
        cout << o.x << ' ' << o.y << ' ' << o.t << ' ' << o.id << endl;
        if (o.t <= m) {
            if (o.id > 0) bit.add(o.y, 1);
            else bit.add(o.y, -1);
        } else {
            if (o.id > 0) ans[o.id] += bit.qry(maxn - 1) - bit.qry(o.y);
            else ans[-o.id] -= bit.qry(maxn - 1) - bit.qry(o.y);
        }
    } 
    for (auto o : op) {
        if (o.t <= m) {
            if (o.id > 0) bit.add(o.y, -1);
            else bit.add(o.y, 1);
        }
    }
    vector<operation> ql, qr;
    for (auto o : op) {
        if (o.t <= m) ql.push_back(o);
        else qr.push_back(o);
    }
    cdq(ql, l, m); cdq(qr, m + 1, r);
} 

void cdq2(const vector<operation> &op, int l, int r) {
    if (op.size() == 0) return;
    if (l >= r) return;
    int m = (l + r) >> 1;
    for (auto o : op) {
        if (o.t <= m) {
            if (o.id > 0) bit.add(o.y, 1);
            else bit.add(o.y, -1);
        } else {
            if (o.id > 0) ans[o.id] += bit.qry(o.y);
            else if (o.id < 0) ans[-o.id] -= bit.qry(o.y);
        }
    } 
    for (auto o : op) {
        if (o.t <= m) {
            if (o.id > 0) bit.add(o.y, -1);
            else bit.add(o.y, 1);
        }
    }
    vector<operation> ql, qr;
    for (auto o : op) {
        if (o.t <= m) ql.push_back(o);
        else qr.push_back(o);
    }
    cdq2(ql, l, m); cdq2(qr, m + 1, r);
} 

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) a[i] = i;
    vector<operation> op;
    int t = 0;
    for (int i = 1; i <= n; ++i) {
        op.push_back({ i, a[i], ++t, 0 });
    }
    for (int i = 1; i <= q; ++i) {
        int l, r; cin >> l >> r;
        if (l > r) swap(l, r);
        op.push_back({ l, a[l], ++t, -i });
        op.push_back({ l, a[r], ++t, i });
        op.push_back({ r, a[r], ++t, -i });
        op.push_back({ r, a[l], ++t, i });
        swap(a[l], a[r]);
        // op.push_back({ 1, n, ++t, i });
    }
    sort(op.begin(), op.end());
    bit.init();
    cdq(op, 1, t);
    for (int i = 1; i <= q; ++i) cout << ans[i] << endl;
    sort(op.begin(), op.end()); reverse(op.begin(), op.end());
    cdq2(op, 1, t);
    for (int i = 1; i <= q; ++i) cout << ans[i] << endl;
    return 0;
}

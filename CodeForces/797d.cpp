#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int l[maxn], r[maxn], v[maxn], fa[maxn];
vector<int> ord;

void dfs(int);

struct BIT {
    int bit[maxn];
    void init() {
        memset(bit, 0, sizeof(bit));
    }
#define lowbit(x) (x & -x)
    void add(int x, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) bit[i] += v;
    }
    int sum(int x) {
        int ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret += bit[i];
        return ret;
    }
#undef lowbit
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    bit.init();
    for (int i = 1; i <= n; ++i) {
        cin >> v[i] >> l[i] >> r[i];
        if (l[i] != -1) fa[l[i]] = i;
        if (r[i] != -1) fa[r[i]] = i;
    }
    int root = 0;
    for (int i = 1; i <= n; ++i) if (!fa[i]) root = i;
    dfs(root);
    vector<int> val;
    for (int i : ord) cerr << v[i] << ' ';
    for (int i = 1; i <= n; ++i) val.push_back(v[i]);
    sort(val.begin(), val.end()); val.resize(unique(val.begin(), val.end()) - val.begin());
    long long inv = 0;
    for (int i = 0; i < ord.size(); ++i) {
        int ind = lower_bound(val.begin(), val.end(), v[ord[i]]) - val.begin() + 1;
        inv += i - bit.sum(ind);
        bit.add(ind, 1);
    }
    cout << (inv + 1) / 2 << '\n';
    return 0;
}

void dfs(int x) {
    if (l[x] != -1) dfs(l[x]);
    ord.push_back(x);
    if (r[x] != -1) dfs(r[x]);
}

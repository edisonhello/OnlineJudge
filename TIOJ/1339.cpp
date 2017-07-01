#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, mod = 1000000009;
pair<int, int> p[maxn];
vector<int> v;

struct BIT {
    int _bit[2][maxn];
    void init() {
        memset(_bit, 0, sizeof(_bit));
    }
#define lowbit(x) (x & -x)
    void add(int x, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) {
            _bit[0][i] = (_bit[0][i] + v) % mod;
            ++_bit[1][i];
        }
    }
    pair<int, int> qry(int x) {
        pair<int, int> ret = make_pair(0, 0);
        for (int i = x; i; i -= lowbit(i)) {
            ret.first = (ret.first + _bit[0][i]) % mod;
            ret.second += _bit[1][i];
        }
        return ret;
    }
#undef lowbit
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> p[i].first >> p[i].second, v.push_back(p[i].second);
    bit.init();
    sort(p, p + n); sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int ind = lower_bound(v.begin(), v.end(), p[i].second) - v.begin() + 1;
        int prod = (long long)p[i].first * (long long)p[i].second % mod;
        pair<int, int> qry = bit.qry(ind);
        int add = ((long long)prod * (long long)qry.second % mod - (long long)qry.first) % mod;
        add = ((add % mod) + mod) % mod;
        ans = (ans + add) % mod;
        bit.add(ind, prod);
    }
    cout << ans << endl;
    return 0;
}

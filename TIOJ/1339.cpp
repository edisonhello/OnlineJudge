#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e6 + 10, mod = 1000000009;
pair<int, int> p[maxn];

struct BIT {
    pair<int, int> bit[maxn];
    void init() {
        memset(bit, 0, sizeof(bit));
    }
#define lowbit(x) (x & -x)
    void add(int x, int v) {
        for (int i = x; i < maxn; i += lowbit(i)) {
            bit[i].first++;
            bit[i].second = (bit[i].second + v) % mod;
        }
    }
    pair<int, int> sum(int x) {
        pair<int, int> ret = make_pair(0, 0);
        for (int i = x; i; i -= lowbit(i)) {
            ret.first += bit[i].first;
            ret.second = (ret.second + bit[i].second) % mod;
        }
        return ret;
    }
#undef lowbit
} bit;

main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
        v.push_back(p[i].second);
    }
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    sort(p, p + n, [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;        
    });
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int ind = lower_bound(v.begin(), v.end(), p[i].second) - v.begin() + 1;
        pair<int, int> qry = bit.sum(ind);
        ans += (((long long)p[i].first * (long long)p[i].second) % mod * (long long)qry.first) % mod - qry.second;
        ans = (ans % mod + mod) % mod;
        bit.add(ind, (long long)p[i].first * (long long)p[i].second % mod);
    }
    cout << ans << '\n';
    return 0;
}

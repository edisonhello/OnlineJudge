#include <bits/stdc++.h>
using namespace std;

const int maxn = 6e5 + 10;
int n, m, s[maxn], a[maxn], b[maxn];

inline bool check(int t) {
    vector<int> ts(s, s + maxn);
    bitset<maxn> v;
    for (int i = 0; i < t; ++i) swap(ts[a[i]], ts[b[i]]);
    int c = 0;
    for (int i = 0; i < n; ++i) if (!v[i]) {
        int now = i;
        ++c;
        while (!v[now]) v[now] = true, now = ts[now];
    }
    return n - c <= t;
}

void solve(int t) {
    vector<int> ts(s, s + maxn);
    for (int i = 0; i < t; ++i) swap(ts[a[i]], ts[b[i]]); 
    bitset<maxn> v;
    vector<pair<int, int>> sw;
    for (int i = 0; i < n; ++i) if (!v[i]) {
        int now = i;
        vector<int> cycle;
        while (!v[now]) v[now] = true, cycle.push_back(now), now = ts[now];
        for (size_t j = 0; j < cycle.size() - 1; ++j) sw.emplace_back(cycle[j], cycle[j + 1]);
    }
    while (sw.size() < t) sw.emplace_back(0, 0);
    vector<int> pos(maxn);
    for (int i = 0; i < n; ++i) pos[s[i]] = i;
    for (int i = 0; i < t; ++i) {
        swap(pos[s[a[i]]], pos[s[b[i]]]); swap(s[a[i]], s[b[i]]);
        cout << pos[sw[i].first] << ' ' << pos[sw[i].second] << endl;
        swap(pos[sw[i].first], pos[sw[i].second]); swap(s[pos[sw[i].first]], s[pos[sw[i].second]]);     
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i) cin >> s[i];
        cin >> m;
        for (int i = 0; i < m; ++i) cin >> a[i] >> b[i];
        int d = 1, ans = m; while (d < maxn) d <<= 1;
        while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
        cout << ans << endl;
        solve(ans);
    }
    return 0;
}

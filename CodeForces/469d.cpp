#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> vec;

class TwoSat {
    private:
        vector<int> G[maxn << 1];
        bool v[maxn << 1];
        int s[maxn << 1], c, n;
        bool dfs(int now, bool check) {
            if (v[now ^ 1]) return false;
            if (v[now]) return true;
            if (check && !G[now].size()) return false;
            v[now] = true;
            s[c++] = now;
            for (int u : G[now]) if (!dfs(u, false)) return false;
            return true;
        }
    public:
        TwoSat(int n): n(n) {
            memset(v, false, sizeof(v));
            memset(s, 0, sizeof(s));
        }
        void add_edge(int a, int b) {
            G[a].push_back(b);
        }
        bool solve() {
            for (int i = 2; i <= 2 * n + 1; ++i)  {
                cout << "i = " << i << endl;
                for (int j : G[i]) cout << j << ' '; cout << endl;
            }
            for (int i = 2; i <= n * 2; i += 2) {
                // cout << "solve i = " << i << " i + 1 = " << i + 1 << endl;
                if (!v[i] && !v[i + 1]) {
                    c = 0;
                    // cout << "try dfs(" << i << ")" << endl;
                    if (!dfs(i, true)) {
                        while (c) v[s[--c]] = false;
                        // cout << "try dfs(" << i + 1 << ")" << endl;
                        if (!dfs(i + 1, true)) {
                            cout << "no = " << i << endl;
                            return false;
                        }
                        else vec.push_back(i + 1);
                    } else vec.push_back(i);
                } else {
                    // cout << "jizz" << endl;
                    // cout << v[i] << ' ' << v[i + 1] << endl;
                    if (v[i]) vec.push_back(i);
                    if (v[i + 1]) vec.push_back(i + 1);
                }
            }
            return true;
        }
};

int p[maxn], fin[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, a, b; cin >> n >> a >> b;
    for (int i = 1; i <= n; ++i) cin >> p[i];
    vector<int> s;
    for (int i = 1; i <= n; ++i) s.push_back(i);
    TwoSat t(n);
    sort(s.begin(), s.end(), [&](const int& a, const int& b) { return p[a] < p[b]; });
    for (int i = 1; i <= n; ++i) {
        bool ok = false;
        int it = lower_bound(s.begin(), s.end(), a - p[i], [&](const int& i, const int& j) { return p[i] < j; }) - s.begin();
        if (it < n && p[s[it]] == a - p[i]) t.add_edge(i << 1, s[it] << 1), ok = true;
        it = lower_bound(s.begin(), s.end(), b - p[i], [&](const int& i, const int& j) { return p[i] < j; }) - s.begin();
        if (it < n && p[s[it]] == b - p[i]) t.add_edge(i << 1 | 1, s[it] << 1 | 1), ok = true;
        if (!ok) {
            cout << "Oh jizz" << endl;
            return 0;
        }
    }
    bool ans = t.solve();
    if (!ans) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    for (int i : vec) if (i <= n * 2 + 1) {
        // cout << i << ' '; 
        if (i & 1) fin[i / 2] = 1;
        else fin[i / 2] = 0;
    }
    for (int i = 1; i <= n; ++i) cout << fin[i] << ' '; cout << endl;
    return 0;
}

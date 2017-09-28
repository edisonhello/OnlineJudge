#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int p[maxn], opt[maxn];
bool v[maxn];
vector<int> G[maxn];

void init1(int n) {
    int a = n / 2, b = n / 2 + 1;
    for (int i = 1; i <= n / 2; ++i) {
        opt[a] = i;
        opt[b] = n - i + 1;
        int t = a;
        if (a > b) {
            a = b - 1;
            b = t + 1;
        } else {
            a = b + 1;
            b = t - 1;
        }
    }
}

void init2(int n) {
    int b = n / 2, a = n / 2 + 1;
    for (int i = 1; i <= n / 2; ++i) {
        opt[a] = i;
        opt[b] = n - i + 1;
        int t = a;
        if (a > b) {
            a = b - 1;
            b = t + 1;
        } else {
            a = b + 1;
            b = t - 1;
        }
    }
}

int dfs(int now) {
    int ret = 1;
    v[now] = true;
    for (int u : G[now]) if (!v[u]) {
        ret += dfs(u);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        for (int i = 1; i <= n; ++i) cin >> p[i];
        init1(n);
        // for (int i = 1; i <= n; ++i) cout << opt[i] << ' '; cout << endl;
        for (int i = 0; i < maxn; ++i) G[i].clear();
        for (int i = 1; i <= n; ++i) G[p[i]].push_back(opt[i]);
        memset(v, false, sizeof(v));
        int cur = 0;
        for (int i = 1; i <= n; ++i) if (!v[i]) {
            int sz = dfs(i);
            cur += sz - 1;
        }
        int ans = cur;
        init2(n);
        // for (int i = 1; i <= n; ++i) cout << opt[i] << ' '; cout << endl;
        for (int i = 0; i < maxn; ++i) G[i].clear();
        for (int i = 1; i <= n; ++i) G[p[i]].push_back(opt[i]);
        memset(v, false, sizeof(v));
        cur = 0;
        for (int i = 1; i <= n; ++i) if (!v[i]) {
            int sz = dfs(i);
            cur += sz - 1;
        }
        cout << min(ans, cur) << endl;
    }
    return 0;
}

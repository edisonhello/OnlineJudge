#include <bits/stdc++.h>
#define int long double
using namespace std;

const int32_t maxn = 1e5 + 10;
const long long inf = 1e18;
int ans, a[maxn], mul[maxn], sum, m;
vector<int32_t> G[maxn];

int lcm(long long a, long long b) {
    return a * (b / (long long)__gcd(a, b));
}

void dfs(int32_t now, int32_t fa) {
    mul[now] = 1;
    if (G[now].size() == 1) return;
    a[now] = inf;
    int ch = 0;
    for (int32_t u : G[now]) if (u != fa) {
        dfs(u, now);
        a[now] = min(a[now], a[u]);
        ++ch;
    }
    for (int32_t u : G[now]) if (u != fa) mul[now] = lcm(mul[now], mul[u] * ch); 
    a[now] *= ch;
}

void go(int32_t now, int32_t fa, int val) {
    if (G[now].size() == 1) {
        if (a[now] < val * m) {
            cout << sum << endl;
            exit(0);
        }
        ans += a[now] - val * m;
        return;
    }
    int ch = 0;
    for (int u : G[now]) if (u != fa) ++ch;
    for (int u : G[now]) if (u != fa) {
        go(u, now, val / ch);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int32_t i = 1; i <= n; ++i) cin >> a[i], sum += a[i];
    for (int32_t i = 0; i < n - 1; ++i) {
        int32_t a, b; cin >> a >> b;
        G[a].emplace_back(b); G[b].emplace_back(a);
    }
    dfs(1, 0);
    m = a[1] / mul[1];
    go(1, 0, mul[1]);
    cout << ans << endl;
    return 0;
}

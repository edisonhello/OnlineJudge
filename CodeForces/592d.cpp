#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
vector<int> G[maxn];
int dp[2][maxn], dep[maxn], p[maxn];
bool c[maxn], v[maxn];

void dfs(int now, int fa, int d) {
    int ch = 0; dep[now] = d; p[now] = fa;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, d + 1);
        c[now] |= c[u];
        if (c[u]) {
            dp[0][now] += 2 + dp[0][u];
            dp[1][now] += 1 + dp[1][u];
        } 
    }
    // cout << "now = " << now << " dp = " << dp[0][now] << ' ' << dp[1][now] << endl;
}

void dfs2(int now, int fa) {
    v[now] = true;
    for (int u : G[now]) if (u != fa) dfs2(u, now);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    vector<int> meow;
    for (int i = 0; i < m; ++i) {
        int a; cin >> a;
        meow.push_back(a); c[a] = true;
    }
    dfs(1, 0, 0);
    sort(meow.begin(), meow.end(), [](const int& a, const int& b) { return dep[a] < dep[b]; });
    int mx = 0, ed = -1, ans = 0;
    for (int i : meow) {
        if (v[i]) continue;
        // cout << i << endl;
        dfs2(i, p[i]); v[i] = false;
        if (dp[0][i] - dp[1][i] + dep[i] > mx) {
            mx = dp[0][i] - dp[1][i] + dep[i];
            ed = i;
        }
        ans += dp[0][i] + 2 * dep[i];
    }
    int mxx = 0, loc = -1;
    // cout << "ans = " << ans << endl;
    for (int i : meow) {
        if (!v[i] && i != ed) {
            if (dep[i] > mxx) mxx = dep[i], loc = i;
        }
    }
    if (loc == -1) loc = ed;
    cout << loc << endl;
    ans -= mxx; ans -= mx;
    cout << ans << endl;
    return 0;
}

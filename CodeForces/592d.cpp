#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10, inf = 1e9 + 1;
vector<int> G[maxn];
bool sup[maxn];
int sub[maxn], dp[3][maxn], p[20][maxn], dep[maxn], t[3][maxn], d[20][maxn];

void dfs2(int now, int fa, int e) {
    // cout << "dfs2: " << now << endl;
    d[0][now] = e;
    for (int i = 1; ; ++i) {
        if ((1 << i) > dep[now]) break;
        d[i][now] = d[i - 1][now] + d[i - 1][p[i - 1][now]];
    }
    for (int u : G[now]) if (u != fa) if (sub[u]) {
        dfs2(u, now, (int)sup[now]);
        dp[0][now] += 2 + dp[0][u];
    }
    if (sub[now] == 1 && sup[now]) return;
    dp[1][now] = dp[2][now] = inf;
    for (int u : G[now]) if (u != fa) if (sub[u]) {
        int tmp = 1 + dp[1][u] + dp[0][now] - 2 - dp[0][u];
        // cout << "tmp = " << tmp << endl;
        if (tmp < dp[1][now]) {
            dp[2][now] = dp[1][now]; t[2][now] = t[1][now];
            dp[1][now] = tmp; t[1][now] = u;
        } else if (tmp < dp[2][now]) {
            dp[2][now] = tmp; t[2][now] = u;
        }
    }
}

void dfs1(int now, int fa, int d) {
    dep[now] = d;
    p[0][now] = fa;
    for (int i = 1; ; ++i) {
        if ((1 << i) > d) break;
        p[i][now] = p[i - 1][p[i - 1][now]];
    }
    sub[now] = (int)sup[now];
    for (int u : G[now]) if (u != fa) {
        dfs1(u, now, d + 1);
        sub[now] += sub[u];
    }
}

int lca(int a, int b) {
    if (dep[a] > dep[b]) swap(a, b);
    int ret = 0;
    for (int i = 0; i < 20; ++i) {
        if ((dep[b] - dep[a]) >> i & 1) {
            ret += d[i][b];
            b = p[i][b];
        }
    }
    if (a == b) return ret;
    for (int i = 19; i >= 0; --i) {
        if (p[i][a] != p[i][b]) {
            ret += d[i][a] + d[i][a];
            a = p[i][a]; b = p[i][b];
        }
        if (a == b) return ret;
    }
    ret += d[0][a];
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    for (int i = 0; i < m; ++i) {
        int tmp; cin >> tmp;
        sup[tmp] = true;
    }
    dfs1(1, 0, 0); dfs2(1, 0, 0); 
    for (int i = 1; i <= n; ++i) cout << "sub[" << i << "] = " << sub[i] << endl;
    for (int i = 1; i <= n; ++i) cout << "dp[" << i << "] = " << dp[0][i] << ' ' << dp[1][i] << ' ' << dp[2][i] << ' ' << t[1][i] << ' ' << t[2][i] << endl;
    int ans = inf, pos = -1;
    for (int i = 1; i <= n; ++i) if (sup[i]) {
        int cur = i;
        for (int j = 19; j >= 0; --j) {
            if (dep[cur] - (1 << j) < 0) continue;
            if (sub[p[j][cur]] < m) cur = p[j][cur];
        }
        int par = cur;
        if (sub[cur] < m) cur = p[0][cur];
        int dis = inf;
        if (cur == 0) dis = dp[1][i];
        else if (t[1][cur] != par) {
            dis = min({ dis, dp[1][cur] - dep[i] + dep[cur] + dp[0][i] - lca(i, cur) + (int)sup[i], dp[2][cur] });
        } else {
            dis = min({ dis, dp[1][cur], dp[2][cur] - dep[i] + dep[cur] + dp[0][i] - lca(i, cur) + (int)sup[i] });
        }
        cout << "i = " << i << " dis = " << dis << endl;
        if (dis < ans) {
            ans = dis; pos = i;
        }
    }
    cout << pos << endl; cout << ans << endl;
    return 0;
}

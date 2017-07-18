#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int p[maxn], sz[maxn];

void dfs(int now, int fa) {
    p[now] = fa; sz[now] = 1;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
        sz[now] += sz[u];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0);
    vector<int> pt; pt.push_back(n);
    int cur = n;
    while (p[cur]) {
        pt.push_back(p[cur]);
        cur = p[cur];
    }
    int ans1 = sz[1] - sz[pt[pt.size() / 2 - 1]], ans2 = sz[pt[pt.size() / 2 - 1]];
    cout << (ans1 > ans2 ? "Fennec" : "Snuke") << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
vector<int> G[maxn];
int ans[maxn];

void dfs(int now, int cur, int fa) {
    if (cur >= ans[now]) return;
    ans[now] = cur;
    for (int u : G[now]) if (u != fa) dfs(u, min(cur, u), now);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].emplace_back(b); G[b].emplace_back(a);
    }
    fill(ans, ans + maxn, n + 1);
    int last = 0, bst = n + 1;
    while (q--) {
        int t, z; cin >> t >> z;
        int x = (z + last) % n + 1;
        if (t == 1) dfs(x, x, 0), bst = min(bst, ans[x]);
        else cout << min(ans[x], bst) << endl, last = min(ans[x], bst);
    }
    return 0;
}

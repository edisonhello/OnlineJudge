#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
int c[maxn], k;
vector<int> G[maxn];

void dfs(int now, int fa, int co) {
    // cout << "now = " << now << " co = " << co << endl;
    c[now] = co;
    int ind = 1;
    if (fa) ++ind;
    for (int u : G[now]) if (u != fa) {
        dfs(u, now, k - ind);
        ++ind;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n >> k;
    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    dfs(1, 0, k);
    int ans = 1;
    for (int i = 1; i <= n; ++i) ans = ans * 1ll * c[i] % mod;
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> G[maxn];
int c[maxn], cnt[2];
bool bi;

void dfs(int now, int co) {
    c[now] = co; ++cnt[co];
    for (int u : G[now]) {
        if (c[u] == c[now]) {
            bi = false;
            continue;
        }
        if (c[u] != -1) continue;
        dfs(u, co ^ 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        G[a].push_back(b); G[b].push_back(a);
    }
    bi = true;
    memset(c, -1, sizeof(c));
    dfs(1, 0);
    // cout << bi << endl;
    if (bi) return cout << cnt[0] * 1ll * cnt[1] - m << endl, 0;
    cout << n * 1ll * (n - 1) / 2 - m << endl;
    return 0;
}

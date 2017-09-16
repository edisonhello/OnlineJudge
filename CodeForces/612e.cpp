#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int p[maxn], ans[maxn];

void dfs(int now) {
    ans[now] = p[p[p[now]]];
    if (!ans[p[now]]) dfs(p[now]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
        if (p[i] == i) return cout << "-1" << endl, 0;
    }
    for (int i = 1; i <= n; ++i) if (!ans[i]) dfs(i);
    for (int i = 1; i <= n; ++i) cout << ans[i] << ' '; cout << endl;
    return 0;
}

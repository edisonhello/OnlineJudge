#include <bits/stdc++.h>
using namespace std;

const int maxn = 300 + 10;
int a[maxn][maxn];
vector<pair<int, int>> G[maxn * maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, p; cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> a[i][j];
    return 0;
}

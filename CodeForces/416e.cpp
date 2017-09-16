#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10, inf = 1e9;
int w[maxn][maxn], sz[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < maxn; ++i) {
        w[i][i] = 0;
        for (int j = 0; j < maxn; ++j) {
            if (i != j) w[i][j] = inf;
        }
    }
    while (m--) {
        int a, b, c; cin >> a >> b >> c;
        w[a][b] = w[b][c] = c;
    }
    for (int i = 1; i <= n; ++i)
}

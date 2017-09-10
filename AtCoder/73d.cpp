#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 10, inf = 1e9 + 1;
int w[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, r; cin >> n >> m >> r;
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) w[i][j] = inf;
    for (int i = 0; i < maxn; ++i) w[i][i] = 0;
    vector<int> ord(r);
    for (int i = 0; i < r; ++i) cin >> ord[i];
    for (int i = 0; i < m; ++i) {
        int a, b, c; cin >> a >> b >> c;
        w[a][b] = min(w[a][b], c);
        w[b][a] = min(w[b][a], c);
    }
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                w[i][j] = min(w[i][j], w[i][k] + w[k][j]);
            }
        }
    }
    if (r == 2) return cout << w[ord[0]][ord[1]] << endl, 0;
    sort(ord.begin(), ord.end());
    int ans = inf;
    do {
        int cur = 0;
        for (int i = 0; i < r - 1; ++i) cur += w[ord[i]][ord[i + 1]];
        ans = min(ans, cur);
    } while (next_permutation(ord.begin(), ord.end()));
    cout << ans << endl;
    return 0;
}

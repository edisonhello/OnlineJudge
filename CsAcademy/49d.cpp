#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
double p[maxn][maxn], dp[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, a; cin >> t >> a;
    for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= a; ++j) cin >> p[i][j], p[i][j] /= 100.0;
    }
    dp[0][t] = 1.0;
    for (int i = 1; i <= a; ++i) {
        for (int j = 1; j <= t; ++j) {
            dp[i][j] = p[i][j] * dp[i - 1][j] + (1 - p[i][j]) * dp[i - 1][j + 1];
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
bool dp[maxn][maxn][maxn][2], v[maxn][maxn][maxn][2];

bool f(int a, int b, int c, int t) {
    if (a == 0 && b == 0 && c == 0) return false;
    if (v[a][b][c][t]) return dp[a][b][c][t];
    for (int i = 1; i <= a; ++i) dp[a][b][c][t] |= !f(a - i, b, c, t ^ 1);
    for (int i = 1; i <= b; ++i) dp[a][b][c][t] |= !f(a, b - i, c, t ^ 1);
    for (int i = 1; i <= c; ++i) dp[a][b][c][t] |= !f(a, b, c - i, t ^ 1);
    for (int i = 1; i <= min(a, b); ++i) dp[a][b][c][t] |= !f(a - i, b - i, c, t ^ 1);
    for (int i = 1; i <= min(b, c); ++i) dp[a][b][c][t] |= !f(a, b - i, c - i, t ^ 1);
    for (int i = 1; i <= min(c, a); ++i) dp[a][b][c][t] |= !f(a - i, b, c - i, t ^ 1);
    for (int i = 1; i <= min(a, min(b, c)); ++i) dp[a][b][c][t] |= !f(a - i, b - i, c - i, t ^ 1);
    v[a][b][c][t] = true;
    return dp[a][b][c][t];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x, y, z; while (cin >> x, x) {
        cin >> y >> z;
        if (f(x, y, z, 0)) cout << "w" << endl;
        else cout << "l" << endl;
    }
    return 0;
}

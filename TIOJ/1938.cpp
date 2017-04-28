#include <bits/stdc++.h>
using namespace std;

const int maxn = 200 + 5;
long long dp[105][maxn][maxn];

struct BIT {
    long long bit[maxn];
    void init() {
        memset(bit, 0, sizeof(bit));
    }
#define lowbit(x) (x & -x)
    void add(int x, long long v) {
        for (int i = x; i < maxn; i += lowbit(i)) bit[i] = max(bit[i], v);
    }
    long long qry(int x) {
        long long ret = 0;
        for (int i = x; i; i -= lowbit(i)) ret = max(ret, bit[i]);
        return ret;
    }
#undef lowbit
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int m, n, a, b, c, d; cin >> m >> n >> a >> b >> c >> d;
    for (int i = 0; i < n; ++i) {
        bit.init();
        for (int x = 1; x <= m; ++x) {
            for (int y = 1; y <= m; ++y) {
                dp[i][x][y] = bit.qry(y - 1) + (a * i + b * (x - 1) + c * (y - 1)) % d;
            }
            if (i) for (int y = 1; y <= m; ++y) bit.add(y, dp[i - 1][x][y]);
        }
    }
    long long Max = 0;
    for (int i = 1; i <= m; ++i) for (int j = 1; j <= m; ++j) Max = max(Max, dp[n - 1][i][j]);
    cout << Max << '\n';
    return 0;
}

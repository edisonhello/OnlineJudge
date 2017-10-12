#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10, mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int dp[maxn][maxn], a[maxn];

int go1(int n, int cur) {
    if (n < cur) return 0;
    if (n == cur) return 1;
    if (dp[n][cur] != -1) return dp[n][cur];
    return dp[n][cur] = add(go1(n, cur + 1), go1(n - cur, cur));
}

int go2(int n, int k) {
    if (n == 0) return 1;
    if (dp[n][k] != -1) return dp[n][k];
    return dp[n][k] = add(go2(n - 1, k + 1), mul(go2(n - 1, k), k));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    memset(dp, -1, sizeof(dp));
    char ch; cin >> ch;
    int n, k; cin >> n >> k;
    for (int i = 0; i < k; ++i) cin >> a[i];
    if (ch == 'U') {
        for (int i = 0; i < k; ++i) n -= a[i];
        cout << go1(n, 1) << endl;
    } else {
        cout << go2(n - k, k) << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 35000 + 10, maxk = 50 + 10;
int dp[maxk][maxn], a[maxn], tot[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        tot[i] = tot[i - 1];
        if (!v[a[i]]) v[a[i]] = true, ++tot[i];
    }
    for (int j = 1; j <= k; ++j) {
        memset(v, 0, sizeof(v));
        int ptr = n, cnt = 0;
        for (int i = n; i >= 1; --i) {
            while (ptr >= 1 && cnt < tot[i] && ptr > j) {
                if (!v[a[ptr]]) v[a[ptr]] = true, ++cnt;
                --ptr;
            }
            cout << ptr << endl;
            dp[j][i] = dp[j - 1][ptr] + cnt;
        }
    }
    cout << dp[k][n] << endl;
}

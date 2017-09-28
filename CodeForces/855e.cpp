#include <bits/stdc++.h>
using namespace std;

const long long maxv = 1e18;
long long dp[11][60][60];

void init(long long b) {
    cout << "init b = " << b << endl;
    long long n = 1ll;
    dp[b][1][0] = 0; dp[b][1][1] = b;
    for (int i = 2; ; ++i) {
        n *= b;
        if (n > maxv) return;
        for (int j = 0; j <= i; ++j) {
            if (j > 0) dp[b][i][j] += dp[b][i - 1][j - 1] * (b - j + 1);
            if (j < i) dp[b][i][j] += dp[b][i - 1][j + 1] * (j + 1);
        }
    }
}

long long go(int b, long long n, int k, int sgn, bool fnd) {
    cout << "b = " << b << " n = " << n << " k = " << k << " sgn = " << sgn << " fnd = " << fnd << endl;
    if (k == 0) return 0;
    long long tmp = n;
    for (int i = 0; i < k; ++i) tmp /= b;
    int bit = tmp % b;
    if (bit) fnd = true;
    long long add = 0;
    if (!fnd) add = go(b, n, k - 1, -1, fnd);
    else add = go(b, n, k - 1, sgn * -1, fnd);
    long long ret = dp[b][k - 1][1];
    return ret + add * sgn;
}

void debug(int b) {
    for (int i = 1; i <= 5; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << "dp[" << b << "][" << i << "][" << j << "] = " << dp[b][i][j] << endl;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    for (int i = 2; i <= 10; ++i) init(i);
    int q; cin >> q; while (q--) {
        int b; long long l, r; cin >> b >> l >> r;
        debug(b);
        cout << go(b, r, 5, -1, false) - go(b, l - 1, 5, -1, false) << endl;
    }
    return 0; 
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 10, mod = 1e9 + 7;
int f[maxn], invf[maxn];
vector<int> fac[maxn];

int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
int mul(int a, int b) { return a * 1ll * b % mod; }

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

void init() {
    f[0] = 1;
    for (int i = 1; i < maxn; ++i) f[i] = mul(f[i - 1], i);
    for (int i = 0; i < maxn; ++i) invf[i] = fpow(f[i], mod - 2);
}

void sieve() {
    for (int i = 1; i < maxn; ++i) {
        for (int j = 1; j * i < maxn; ++j) fac[i * j].push_back(i);
    }
}

int c(int n, int k) {
    if (n < k) return 0;
    return mul(f[n], mul(invf[k], invf[n - k]));
}

int main() {
    int n, k; cin >> n >> k;
    init(); sieve();
    int ans = 0;
    for (int i = 1; i <= n - 1; ++i) {
        int cur = mul(k, c(n, i));
        cout << "i = " << i << endl;
        bool ok = false;
        int s = 0;
        for (int d : fac[n - i]) if (i != (n - i) / d && d > 1) {
            // cout << "d = " << d << endl;
            // ok = true;
            int cc = c(k - 1, d);
            int p = mul(f[n - i], fpow(fpow(f[(n - i) / d], (n - i) / d), mod - 2));
            cout << f[n - i] << ' ' << fpow(f[(n - i) / d], (n - i) / d) << endl;
            s = add(s, mul(cc, p));
        }
        ans = add(ans, mul(cur, s));
        // if (ok) ans = add(ans, cur);
    }
    cout << ans << endl;
}

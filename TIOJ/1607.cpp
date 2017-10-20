#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7, maxn = 2e6 + 10;
int f[maxn], invf[maxn];

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

void init() {
    f[0] = 1; invf[0] = 1;
    for (int i = 1; i < maxn; ++i) {
        f[i] = mul(f[i - 1], i);
        invf[i] = fpow(f[i], mod - 2);
    }
}

int main() {
    init();
    int t; cin >> t; while (t--) {
        int n; cin >> n;
        cout << mul(f[n], mul(invf[n >> 1], invf[(n >> 1) + 1])) << endl;
    }
    return 0;
}

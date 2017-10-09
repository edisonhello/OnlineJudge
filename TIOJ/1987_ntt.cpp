#include <bits/stdc++.h>
#include "lib1987.h"
using namespace std;

const int maxn = 2097152;
// const long long p = 26388279066623, root = 31;
const long long p = 2013265921, root = 31;
long long omega[maxn + 1];

long long mul(long long a, long long b) { return (__int128)a * (__int128)b % p; }

long long fpow(long long a, long long n) {
    long long ret = 1ll;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

void prentt() {
    omega[0] = 1;
    long long r = fpow(root, (p - 1) / maxn);
    for (int i = 1; i <= maxn; ++i) omega[i] = mul(omega[i - 1], r);
}

void ntt(vector<long long>& a, int n, bool inv = false) {
    int basic = maxn / n;
    int theta = basic;
    for (int m = n; m >= 2; m >>= 1) {
        int mh = m >> 1;
        for (int i = 0; i < mh; ++i) {
            long long w = omega[i * theta % maxn];
            for (int j = i; j < n; j += m) {
                int k = j + mh;
                long long x = a[j] - a[k];
                if (x < 0) x += p;
                a[j] += a[k];
                if (a[j] > p) a[j] -= p;
                a[k] = mul(w, x);
            }
        }
        theta = theta * 2 % maxn;
    }
    int i = 0;
    for (int j = 1; j < n - 1; ++j) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
    if (!inv) return;
    long long ni = fpow(n, p - 2);
    reverse(a.begin() + 1, a.end());
    for (int i = 0; i < n; ++i) a[i] = mul(a[i], ni);
}

void multiply(int n, int m, long long *a, long long *b, long long *ans) {
    prentt();
    int d = 1; while (d < max(n + 1, m + 1)) d <<= 1; d <<= 1;
    vector<long long> va(d), vb(d);
    for (int i = 0; i <= n; ++i) va[i] = (a[i] < 0 ? a[i] + p : a[i]);
    for (int i = 0; i <= m; ++i) vb[i] = (b[i] < 0 ? b[i] + p : b[i]);
    ntt(va, d); ntt(vb, d);
    vector<long long> vc(d);
    for (int i = 0; i < d; ++i) vc[i] = mul(va[i], vb[i]);
    ntt(vc, d, true);
    for (int i = 0; i <= n + m; ++i) ans[i] = vc[i];
    for (int i = 0; i <= n + m; ++i) {
        if (ans[i] > p / 2) ans[i] -= p;
    }
}

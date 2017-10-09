#include <bits/stdc++.h>
#include "lib1987.h"
using namespace std;

const int maxn = 2097152;
const long double pi = acos(-1);
const complex<long double> I(0, 1);
complex<long double> omega[maxn + 1];

void prefft() {
    for (int i = 0; i <= maxn; ++i) omega[i] = exp(i * 2 * pi / maxn * I);
}

void fft(vector<complex<long double>>& a, int n, bool inv=false) {
    int basic = maxn / n;
    int theta = basic;
    for (int m = n; m >= 2; m >>= 1) {
        int h = m >> 1;
        for (int i = 0; i < h; ++i) {
            complex<long double> w = omega[inv ? maxn - (i * theta % maxn) : i * theta % maxn];
            for (int j = i; j < n; j += m) {
                int k = j + h;
                complex<long double> x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w * x;
            }
        }
        theta = (theta * 2) % maxn;
    }
    int i = 0;
    for (int j = 1; j < n - 1; ++j) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
    if (inv) for (int i = 0; i < n; ++i) a[i] /= (long double)n;
}
void invfft(vector<complex<long double>>& a, int n) {
    fft(a, n, true);
}

void multiply(int n, int m, long long *a, long long *b, long long *ans) {
    prefft();
    int d = 1; while (d < max(n + 1, m + 1)) d <<= 1; d <<= 1;
    vector<complex<long double>> va(d), vb(d);
    for (int i = 0; i < n + 1; ++i) va[i] = complex<long double>(a[i], 0);
    for (int i = 0; i < m + 1; ++i) vb[i] = complex<long double>(b[i], 0);
    va.resize(d); vb.resize(d);
    fft(va, d); fft(vb, d);
    vector<complex<long double>> vc(d);
    for (int i = 0; i < d; ++i) vc[i] = va[i] * vb[i];
    invfft(vc, d);
    for (int i = 0; i <= n + m; ++i) {
        long double k = vc[i].real();
        if (k > 0) k += 0.5;
        else k -= 0.5;
        ans[i] = (long long)k;
    }
}

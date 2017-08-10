#include <bits/stdc++.h>
using namespace std;

const int maxn = 8388608;
const double pi = acos(-1);
typedef complex<double> cplx;
const cplx I(0, 1);
cplx w[maxn + 10];

void prefft() {
    for (int i = 0; i <= maxn; ++i) w[i] = exp(2.0 * i * pi / maxn * I);
}

void fft(cplx a[], int n) {
    // cout << "fft" << endl;
    int basic = maxn / n;
    int theta = basic;
    for (int m = n; m >= 2; m >>= 1) {
        // cout << "m = " << m << endl;
        int h = m >> 1;
        for (int i = 0; i < h; ++i) {
            for (int j = i; j < n; j += m) {
                int k = j + h;
                cplx x = a[j] - a[k];
                a[j] += a[k];
                a[k] = w[i * theta % maxn] * x;
            }
        }
        theta = (theta * 2) % maxn;
    }
    // cout << "ddd" << endl;
    int i = 0;
    for (int j = 1; j < n - 1; ++j) {
        for (int k = n >> 1; k > (i ^= k); k >>= 1);
        if (j < i) swap(a[i], a[j]);
    }
}

void invfft(cplx a[], int n) {
    fft(a, n);
    vector<cplx> vec(n);
    for (int i = 0; i < n; ++i) vec[i] = a[n - i] / (double)n;
    for (int i = 0; i < n; ++i) a[i] = vec[i];
}

cplx a[maxn], b[maxn], c[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    prefft();
    string s, t; cin >> s >> t;
    for (int i = 0; i < s.length(); ++i) a[i] = cplx(s[i] - '0', 0);
    for (int i = 0; i < t.length(); ++i) b[i] = cplx(t[i] - '0', 0);
    fft(a, maxn); fft(b, maxn);
    for (int i = 0; i < maxn; ++i) c[i] = a[i] * b[i];
    invfft(c, maxn);
    int car = 0;
    for (int i = 0; i < 20; ++i) {
        int k = ((int)c[i].real() + car) % 10;
        cout << k;
        car = ((int)c[i].real() + car) / 10;
    }
    return 0;
}

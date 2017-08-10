#include <bits/stdc++.h>
using namespace std;

const int maxn = 32;
complex<double> omega[maxn + 1];
const double pi = acos(-1);
const complex<double> I(0, 1);

void prefft() {
    for (int i = 0; i <= maxn; ++i) omega[i] = exp(i * 2 * pi / maxn * I);
}

void fft(vector<complex<double>>& a, int n, bool inv=false) {
    int basic = maxn / n;
    int theta = basic;
    for (int m = n; m >= 2; m >>= 1) {
        int h = m >> 1;
        for (int i = 0; i < h; ++i) {
            complex<double> w = omega[inv ? maxn - (i * theta % maxn) : i * theta % maxn];
            for (int j = i; j < n; j += m) {
                int k = j + h;
                complex<double> x = a[j] - a[k];
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
    if (inv) for (int i = 0; i < n; ++i) a[i] /= (double)n;
}

void invfft(vector<complex<double>>& a, int n) {
    fft(a, n, true);
}

int main() {
    vector<complex<double>> a(maxn), b(maxn), c(maxn);
    int aa; cin >> aa;
    for (int i = 0; i < aa; ++i) {
        int x; cin >> x;
        a[i] = complex<double>(x, 0);
    }
    int bb; cin >> bb;
    for (int i = 0; i < bb; ++i) {
        int x; cin >> x;
        b[i] = complex<double>(x, 0);
    }
    fft(a, maxn); fft(b, maxn);
    for (int i = 0; i < maxn; ++i) c[i] = a[i] * b[i];
    invfft(c, maxn);
    for (int i = 0; i < maxn; ++i) cout << c[i].real() << ' '; cout << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 131072;
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

int ans[maxn];

int main() {
    prefft();
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s, t; cin >> s >> t;
    reverse(t.begin(), t.end());
    int d = 1;
    while (d < max(s.length(), t.length())) d <<= 1;
    d <<= 1;
    for (int i = 0; i < 26; ++i) {
        char ch = (char)(i + 'a');
        vector<complex<double>> a(d), b(d), c(d);
        for (int j = 0; j < s.length(); ++j) if (s[j] == ch) a[j] = complex<double>(1, 0);
        for (int j = 0; j < t.length(); ++j) if (t[j] == ch) b[j] = complex<double>(1, 0);
        fft(a, d); fft(b, d);
        for (int j = 0; j < d; ++j) c[j] = a[j] * b[j];
        invfft(c, d);
        for (int j = 0; j < d; ++j) ans[j] += (int)round(c[j].real());
    }
    int len = 0;
    for (int i = 0; i < d; ++i) len = max(len, ans[i]);
    cout << len << endl;
    return 0;
}

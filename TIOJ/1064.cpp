#include <bits/stdc++.h>
#define double long double
using namespace std;

const int maxn = 262144;
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
    if (inv) for (int i = 0; i < n; ++i) a[i] /= n;
}

void invfft(vector<complex<double>>& a, int n) {
    fft(a, n, true);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    prefft();
    string s, t; cin >> s >> t;
    int d = 1; while (d < max(s.length(), t.length())) d <<= 1; d <<= 1;
    vector<complex<double>> a(d), b(d), c(d);
    for (int i = 0; i < s.length(); ++i) a[i] = complex<double>(s[i] - '0', 0);
    for (int i = 0; i < t.length(); ++i) b[i] = complex<double>(t[i] - '0', 0);
    fft(a, d); fft(b, d);
    for (int i = 0; i < d; ++i) c[i] = a[i] * b[i];
    invfft(c, d);
    int ind = d - 1;
    while (ind >= 0 && (int)(c[ind].real() + 0.5) == 0) --ind;
    int car = 0;
    stack<int> st;
    for (; ind >= 0; --ind) {
        int k = car + (int)(c[ind].real() + 0.5);
        st.push(k % 10); car = k / 10;
    }
    if (car) st.push(car);
    while (st.size()) cout << st.top(), st.pop(); cout << endl;
    return 0;
}

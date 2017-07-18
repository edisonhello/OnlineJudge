#include <bits/stdc++.h>
using namespace std;

int f[11];

int fac(int n) {
    if (n == 0) return 1;
    if (f[n]) return f[n];
    return f[n] = fac(n - 1) * n;
}

int c(int n, int k) {
    return fac(n) / fac(n - k) / fac(k);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        cout << c(n + 1, 3) + n + 1 << endl;
    }
    return 0;
}

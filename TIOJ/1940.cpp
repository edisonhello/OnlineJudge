#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int k, n; cin >> k >> n;
    if (k == 1) return cout << n << '\n', 0;
    for (int p = 2; ; p <<= 1) {
        int rem = (p - 1) >> 1;
        if (n % p == rem) {
            if (n / p == 0) return cout << "1\n", 0;
            if (n / p == 1) return cout << "0\n", 0;
            return cout << n / p << '\n', 0;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int T, kase = 0; cin >> T; while (T--) {
        cout << "Case #" << ++kase << ": ";
        long long n, k; cin >> n >> k;
        if (n == k) { cout << "0 0\n"; continue; }
        int osas = (int)log2(k);
        long long jizz = (1LL << (osas + 1));
        cout << (long long)ceil((double)(n - k + 1 - (1LL << osas)) / (double)jizz) << ' ' << (long long)(ceil((double)(n - k + 1 - jizz) / (double)jizz)) << '\n';
    }
    return 0;
}

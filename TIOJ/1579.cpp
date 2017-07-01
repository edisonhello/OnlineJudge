#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 20, mod = 1000000007;
long long c[maxn], mon[] = {1, 5, 10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 500000, 1000000, 5000000, 10000000, 50000000, 100000000, 500000000, 1000000000, 5000000000, 10000000000, 50000000000};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> c[i];
    long long sum = c[0];
    for (int i = 1; i < n; ++i) {
        int tmp = c[i];
        for (int j = 0; j < i; ++j) {
            if (c[j] * mon[j] >= mon[i] && c[i]) c[j] += c[i] * (mon[i] / mon[j]), c[i] = 0;
        }
    } 
    int ans = 1;
    for (int i = 0; i < n; ++i) ans = (long long)ans * (long long)(c[i] + 1) % mod;
    cout << ans - 1 << '\n';
    return 0;
}

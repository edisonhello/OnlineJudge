#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
long long a[maxn], s[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], s[i] = s[i - 1] + a[i];
    s[n + 1] = 0;
    if (s[n] & 1) return cout << "NO\n", 0;
    for (int i = 1; i <= n; ++i) {
        int d = 1, p = 1; while (d <= i) d <<= 1;
        while (d >>= 1) if (p + d <= i) if (s[p + d] <= s[n] / 2 + a[i]) p += d;
        if (s[p] == s[n] / 2 + a[i]) return cout << "YES\n", 0;
        d = 1; p = i + 1; while (d <= n) d <<= 1;
        while (d >>= 1) if (p + d <= n + 1) if (s[p + d] <= s[n] / 2 - a[i]) p += d;
        if (s[p] == s[n] / 2 - a[i]) return cout << "YES\n", 0;
    } 
    cout << "NO\n";
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000009, maxn = 100 + 5;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    a[1] = 1; a[2] = 4; a[3] = 15;
    for (int i = 4; i < maxn; ++i) a[i] = (4 * (long long)a[i - 1] - a[i - 2]) % mod;
    int T; cin >> T; while (T--) {
        int n; cin >> n;
        cout << a[n] << '\n';
    }
    return 0;
}

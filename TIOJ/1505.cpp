#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, g = 0; cin >> n;
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 1; i < n && a[0]; ++i) a[0] /= __gcd(a[0], a[i]);
        if (a[0]) cout << "Asssss!!" << endl;
        else cout << "zzz..." << endl;
    }
    return 0;
}

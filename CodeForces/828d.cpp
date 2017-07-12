#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    int d = (n % 2 == 0 ? n / 2 : n / 2 + 1);
    if (k == 3 && d < n - k + 1) {
        int d = (n % 2 == 0 ? n / 2 : n / 2 + 1); cout << d << endl;
        for (int i = 1; i <= d - 1; ++i) cout << i << ' ' << i + 1 << endl;
        cout << d << ' ' << d + 1 << endl;
        cout <<  d << ' ' << d + 2 << endl;
        for (int i = d + 2; i < n; ++i) cout << i << ' ' << i + 1 << endl;
        return 0;
    }
    cout << n - k + 1 << endl;
    for (int i = 1; i <= k - 1; ++i) cout << i << ' ' << k << endl;
    for (int i = k; i < n; ++i) cout << i << ' ' << i + 1 << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    while (m--) {
        int l, r, x; cin >> l >> r >> x;
        --l, --r; --x;
        int cnt = 0;
        for (int i = l; i <= r; ++i) {
            if (a[i] < a[x]) ++cnt;
        }
        if (cnt == x) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int n, q, c, a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> q >> c;
    for (int i = 0; i < n; ++i) cin >> a[i];
    while (q--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int x, y, k; cin >> x >> y >> k;
            int ind = x, Max = 0;
            for (int i = x; i < y; ++i) {
                if (a[i] == k) Max = max(Max, i - ind), ind = i + 1;
            }
            Max = max(Max, y - ind);
            cout << Max << '\n';
        } else {
            int p, k; cin >> p >> k;
            a[p] = k;
        }
    }
    return 0;
}

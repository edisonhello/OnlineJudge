#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": ";
        int n, r, o, y, g, b, v; cin >> n >> r >> o >> y >> g >> b >> v;
        if (n & 1) cout << "IMPOSSIBLE\n";
        else {
            pair<int, char> a[3]; a[0] = make_pair(r, 'R'); a[1] = make_pair(y, 'Y'); a[2] = make_pair(b, 'B');
            int x = (a[2].first - a[1].first + a[0].first) / 2;
            char last;
            for (int i = 0; i < a[0].first; ++i) {
                cout << a[0].second;
                if (x) cout << a[2].second, --x, last = a[2].second;
                else cout << a[1].second, last = a[1].second;
            }
            if (last == a[2].second) for (int i = 0; i < (n - a[0].first * 2) / 2; ++i) cout << a[1].second << a[2].second;
            else for (int i = 0; i < (n - a[0].first * 2) / 2; ++i) cout << a[2].second << a[1].second;
            cout << '\n';
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    // cout << 200000 << ' ' << 10487 << ' ' << 17788 << endl;
    // for (int i = 0; i < 200000; ++i) {
        // cout << (long long)rand() * (long long)rand() % 1000000 + 1 << ' ';
    // }
    // cout << endl;
    cout << "500000 50000" << endl;
    for (int i = 1; i <= 500000; ++i) cout << (long long)rand() * (long long)rand() % 1000000000 + 1 << ' '; cout << endl;
    for (int i = 0; i < 50000; ++i) {
        int t = rand() % 2 + 1; cout << t << ' ';
        if (t == 1) {
            int l = rand() % 500000 + 1, r = rand() % 500000 + 1, x = (long long)rand() * (long long)rand() % 1000000000 + 1;
            cout << min(l, r) << ' ' << max(l, r) << ' ' << x << endl;
        } else {
            int y = (long long)rand() * (long long)rand() % 1000000000 + 1;
            cout << y << endl;
        }
    }
    return 0;
}

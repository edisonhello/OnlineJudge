#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

set<pair<int, int>> s;
const int maxn = 100000;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    srand(time(nullptr));
    freopen("in.txt", "w", stdout);
    cout << maxn << endl;
    for (int i = 1; i <= maxn; ++i) cout << (rand() * 1ll * rand() % maxn + 1) << ' '; cout << endl;
    cout << maxn << endl;
    for (int i = 0; i < maxn; ++i) {
        int t = rand() % 2 + 1;
        cout << t << ' ';
        if (t == 1) {
            int l = rand() % maxn + 1, r = rand() % maxn + 1;
            cout << l << ' ' << r << endl;
        } else {
            int l = rand() % maxn + 1, r = rand() % maxn + 1, k = rand() % maxn + 1;
            cout << l << ' ' << r << ' ' << k << endl;
        }
    }
    return 0;
}

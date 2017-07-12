#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, a; cin >> n;
    set<int> y;
    for (int i = 0; i < n; ++i) cin >> a, y.insert(a);
    set<int> s;
    for (int i : y) {
        if (i & 1) {
            if ((i - 1) / 2 > 0 && s.find((i - 1) / 2) == s.end()) s.insert((i - 1) / 2);   
            else s.insert(i);
        } else {
            if (i / 2 > 0 && s.find(i / 2) == s.end()) {
                if (y.count(i + 1)) s.insert(i);
                else s.insert(i / 2);
            } else s.insert(i );
        }
    }
    for (int i : s) cout << i << ' '; cout << endl;
    return 0;
}

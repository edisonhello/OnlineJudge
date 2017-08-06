#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e4 + 10;
bool v[maxn];

int main() {
    int n, r; cin >> n >> r;
    while (r--) {
        int a; cin >> a;
        v[a] = true;
    }
    bool ans = false;
    for (int i = 1; i <= n; ++i) {
        if (!v[i]) cout << i << ' ', ans = true;
    }
    if (!ans) cout << "*" << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    double ans = 1e9 + 1;
    int bst = 0;
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        double a, b; cin >> a >> b;
        if (b / a < ans) ans = b / a, bst = i;
    }
    cout << bst << endl;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    int a; cin >> a;
    int ans = 1;
    for (int i = 1; i < n; ++i) {
        int b; cin >> b;
        if (b != a) ++ans;
        a = b;
    }
    cout << ans << '\n';
    return 0;
}

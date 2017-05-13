#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, cnt, ans = 0; cin >> k;
    for (int i = 0; i <= k; ++i) {
        cin >> cnt;
        if (ans >= (1 << i) - 1) ans += cnt * (1 << i);
    }
    cout << ans + 1 << endl;
    return 0;
}

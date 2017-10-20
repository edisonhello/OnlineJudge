#include <bits/stdc++.h>
using namespace std;

int a[3][3];

int main() {
    int ans = 0;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) cin >> a[i][j];
        ans += min(min(a[i][0], a[i][1]), a[i][2]);
    }
    cout << ans << endl;
    return 0;
}

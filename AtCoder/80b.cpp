#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 10;
int a[maxn * maxn], ans[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int h, w; cin >> h >> w;
    int n; cin >> n;
    int x = 1, y = 1, dir = 1;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        while (a[i]--) {
            ans[x][y] = i;
            y += dir;
            if (y == w + 1) y = w, ++x, dir = -1;
            else if (y == 0) y = 1, ++x, dir = 1;
        }
    }
    for (int i = 1; i <= h; ++i) {
        for (int j = 1; j <= w; ++j) cout << ans[i][j] << ' '; cout << endl;
    }
    return 0;
}

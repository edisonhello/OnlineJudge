#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
int deg[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n, n) {
        for (int i = 0; i < n; ++i) cin >> deg[i];
        bool ans = true;
        for (int i = 0; i < n; ++i) {
            sort(deg, deg + n); reverse(deg, deg + n);
            for (int j = i + 1, cnt = 0; cnt < deg[i]; ++cnt, ++j) {
                if (j >= n) {
                    ans = false;
                    break;
                }
                if (deg[j] == 0) --cnt;
                else --deg[j];
            }
        }
        if (ans) cout << "Y" << endl;
        else cout << "N" << endl;
    }
    return 0;
}

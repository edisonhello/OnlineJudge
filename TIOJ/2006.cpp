#include <bits/stdc++.h>
using namespace std;

const int maxn = 400 + 10;
int n, m, cnt[maxn];

bool check() {
    for (int i = 1; i <= n; ++i) if (cnt[i] >= 2) {
        // cout << "i = " << i << endl;
        vector<int> c(maxn);
        for (int j = 0; j < maxn; ++j) c[j] = cnt[j];
        c[i] -= 2;
        bool ok = true;
        for (int j = 1; j <= n; ++j) {
            // cout << "j = " << j << " " << c[j] << endl;
            while (c[j] > 0 && ok) {
                if (c[j] >= 3) c[j] -= 3;
                else {
                    if (c[j + 1] > 0 && c[j + 2] > 0) {
                        --c[j];
                        --c[j + 1];
                        --c[j + 2];
                    } else ok = false;
                }
            }

        }
        if (ok) return true;
    }
    return false;
}

int main() {
    cin >> n >> m;
    int a;
    for (int i = 0; i < 3 * m + 1; ++i) cin >> a, ++cnt[a];
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
        ++cnt[i];
        // cout << "go " << i << endl;
        if (check()) ans.push_back(i);
        --cnt[i];
    }
    if (ans.size() == 0) return cout << "NO" << endl, 0;
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}

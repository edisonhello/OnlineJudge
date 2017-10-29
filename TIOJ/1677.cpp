#include <bits/stdc++.h>
using namespace std;

void naive() {
    vector<int> now = { 0 };
    vector<int> ans[10000];
    for (int i = 0; i < 15; ++i) {
        for (size_t j = 0; j < now.size(); ++j) ans[j + 1].push_back(now[j]);
        vector<int> tmp;
        for (size_t j = 0; j < now.size(); ++j) {
            if (now[j] == 0) tmp.push_back(1);
            else tmp.push_back(0), tmp.push_back(1);
        }
        swap(tmp, now);
    }
    for (int i = 1; i < 10000; ++i) {
        if (ans[i].size() == 0) break;
        for (int j : ans[i]) cout << j << ' '; 
        cout << endl;
    }
}

int main() {
    naive();
    int m; cin >> m; while (m--) {
        int n, k; cin >> n >> k;
        if (k == 1 || k == 2) {
            if (k == 1) cout << (n + 1) % 2 << endl;
            else cout << n % 2 << endl;
            continue;
        }
        int f = 1, pf = 0;
        bool ans = false;
        for (int i = 0; i < n; ++i) {
            if (f >= k) ans = true;
            if (f < 0) break;
            int t = f; f += pf; pf = t;
        } 
        if (!ans) {
            cout << -1 << endl;
            continue;
        }
        k -= 3; k %= 5;
        if (k == 0 || k == 2 || k == 3) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}

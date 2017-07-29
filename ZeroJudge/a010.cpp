#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; while (cin >> n) {
        int p = 2;
        vector<pair<int, int>> ans;
        while (n > 1) {
            int cnt = 0;
            while (n % p == 0) n /= p, ++cnt;
            if (cnt) ans.push_back(make_pair(p, cnt));
            ++p;
        }
        if (ans[0].second > 1) cout << ans[0].first << "^" << ans[0].second;
        else cout << ans[0].first;
        for (int i = 1; i < ans.size(); ++i) {
            cout << " * ";
            if (ans[i].second > 1) cout << ans[i].first << "^" << ans[i].second;
            else cout << ans[i].first;
        }
        cout << endl;
    }
    return 0;
}

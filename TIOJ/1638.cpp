#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn = 1e5 + 10;
const int inf = 1e18 + 1;

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 0; i < n; ++i) {
        int x, y, k; cin >> x >> y >> k;
        vec.emplace_back(x * x + y * y, k);
    }
    sort(vec.begin(), vec.end());
    int curmin = 0, cur = 0, ans = 0;
    for (size_t i = 0; i < vec.size(); ) {
        size_t j = i;
        while (j < vec.size() && vec[j].first == vec[i].first) cur += vec[j].second, ++j;
        ans = max(ans, cur - curmin);
        curmin = min(curmin, cur);
        i = j;
    }
    cout << ans << endl;
    return 0;
}

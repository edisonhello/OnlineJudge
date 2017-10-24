#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int n;
vector<int> ans;
bool e[maxn];

void go(int l, int r) {
    // cout << "l = " << l << " r = " << r << endl;
    if (l > r) return;
    int m = (l + r) >> 1;
    ans.push_back(m);
    bool d = false;
    if (m - 1 > 0) ans.push_back(m - 1), d = true;
    if (m + 1 <= n) ans.push_back(m + 1), d = true;
    if (d && (!e[m + 1] || !e[m - 1])) ans.push_back(m);
    e[m] = true; e[m + 1] = e[m - 1] = true;
    go(l, m - 2); go(m + 2, r);
}

int main() {
    cin >> n;
    e[n + 1] = e[0] = true;
    go(1, n);
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}

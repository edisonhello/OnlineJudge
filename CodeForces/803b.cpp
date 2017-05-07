#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
set<int> s[maxn];
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> v;
    for (int i = 1; i <= n; ++i) cin >> a[i], v.push_back(a[i]);
    sort(v.begin(), v.end()); v.resize(unique(v.begin(), v.end()) - v.begin());
    for (int i = 1; i <= n; ++i) {
        int ind = lower_bound(v.begin(), v.end(), a[i]) - v.begin();
        s[ind].insert(i);
    }
    int z = lower_bound(v.begin(), v.end(), 0) - v.begin();
    for (int i = 1; i <= n; ++i) {
        auto it = s[z].lower_bound(i);
        int pos = abs(*it - i); --it; pos = min(pos, abs(*it - i));
        cout << pos << ' ';
    }
    return 0;
}

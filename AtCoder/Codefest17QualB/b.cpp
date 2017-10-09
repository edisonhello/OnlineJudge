#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    multiset<int> ms;
    while (n--) {
        int d; cin >> d;
        ms.insert(d);
    }
    int m; cin >> m;
    while (m--) {
        int t; cin >> t;
        if (!ms.count(t)) return cout << "NO" << endl, 0;
        ms.erase(ms.find(t));
    }
    cout << "YES" << endl;
    return 0;
}

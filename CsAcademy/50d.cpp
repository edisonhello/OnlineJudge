#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; ++i) cin >> vec[i].first >> vec[i].second;
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });
    multiset<int> s;
    for (int i = 0; i < n; ++i) {
        if (s.empty()) {
            s.insert(vec[i].first);
            continue;
        }
        auto it = s.lower_bound(vec[i].first);
        if (it == s.begin()) {
            s.insert(vec[i].first);
            continue;
        }
        --it;
        s.erase(s.find(*it));
        s.insert(vec[i].first);
    } 
    cout << s.size() << endl;
    return 0;
}

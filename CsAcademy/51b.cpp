#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> vec;
    for (int i = 1; i <= n; ++i) {
        int a; cin >> a;
        vec.emplace_back(i, a);
    }
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first + a.second == b.first + b.second ? a.second < b.second : a.first + a.second < b.first + b.second;
    });
    for (auto i : vec) cout << i.first << ' '; cout << endl;
}

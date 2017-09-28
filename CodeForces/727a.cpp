#include <bits/stdc++.h>
using namespace std;

int b;
vector<int> ans;

void go(int a, const vector<int>& vec) {
    if (vec.size() > ans.size()) return;
    if (a > b) return;
    if (a == b) {
        if (vec.size() < ans.size()) ans = vec;
        return;
    }
    vector<int> v(vec.begin(), vec.end()); v.push_back(a * 2);
    go(a * 2, v);
    v.pop_back(); v.push_back(a * 10 + 1);
    go(a * 10 + 1, v);
}

int main() {
    int a; cin >> a >> b;
    ans = vector<int>(40);
    go(a, vector<int>());
    if (ans.size() == 40) return cout << "NO" << endl, 0;
    cout << "YES" << endl;
    cout << ans.size() + 1 << endl;
    cout << a << ' ';
    for (int i : ans) cout << i << ' '; cout << endl;
    return 0;
}

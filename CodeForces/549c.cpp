#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], n, k, c[2];
map<pair<int, int>, int> dp;

int mex(vector<int> vec) {
    bitset<10> v;
    for (int i : vec) v[i] = true;
    for (int i = 0; ; ++i) {
        if (!v[i]) return i;
    }
}

int go(int n, int o) {
    if (n == k) return o & 1;
    if (dp.count(make_pair(n, o))) return dp[make_pair(n, o)];
    int e = n - o;
    vector<int> sg;
    if (o > 1) sg.push_back(go(n - 1, o - 1));
    if (e > 1) sg.push_back(go(n - 1, o));
    return dp[make_pair(n, o)] = mex(sg);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i], ++c[a[i] & 1];
    cout << (go(n, c[1]) ? "Stannis" : "Daenerys") << endl;
    return 0;
}

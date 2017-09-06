#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;
int t[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, m; cin >> n >> k >> m;
    vector<int> vec;
    long long sum = 0;
    for (int i = 1; i <= k; ++i) cin >> t[i], vec.push_back(i), sum += t[i];
    sort(vec.begin(), vec.end(), [&](const int&a, const int& b) { return t[a] < t[b]; });
    long long ans = (m / sum) + (m / sum) * (k + 1);
    m %= sum;
    for (int i = 0; i < k; ++i) {
        if (m -= t[vec[i]] < 0) break;
        ++ans; m -= t[vec[i]];
    }
    cout << ans << endl;
    return 0;
}

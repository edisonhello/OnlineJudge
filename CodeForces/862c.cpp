#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, maxv = 1e6, bit = 30;
int a[maxn];

int main() {
    int n, x; cin >> n >> x;
    int k = 0;
    vector<int> ans;
    for (int i = 1; i <= n - 2; ++i) ans.push_back(i), k ^= i;
    for (int i = n - 1; i <= maxv; ++i) {
        // cout << i << ' ' << (x ^ k ^ i) << endl;
        if ((x ^ k ^ i) != i && (x ^ k ^ i) > n - 2 && (x ^ k ^ i) <= maxv) {
            ans.push_back(i);
            ans.push_back(x ^ k ^ i);
            cout << "YES" << endl;
            for (int j : ans) cout << j << ' '; cout << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0; 
}

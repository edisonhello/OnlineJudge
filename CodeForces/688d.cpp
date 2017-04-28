#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000 + 5;
int c[maxn];
bool v[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
        if (v[c[i] % k]) return cout << "YES\n", 0;
        v[c[i] % k] = true;
    }
    cout << "NO\n";
    return 0;
}

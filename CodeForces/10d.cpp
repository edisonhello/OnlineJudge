#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 10;
int a[maxn], b[maxn], dp[maxn][maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int m; cin >> m;
    for (int i = 1; i <= m; ++i) cin >> b[i];
    return 0;
}

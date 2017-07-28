#include <bits/stdc++.h>
using namespace std;

const int maxn = 1500 + 10, maxxor = 1048576, inf = 1e9 + 1;
int w[maxn][maxn], r[maxn], dp[2][maxxor << 1];
vector<pair<int, int>> vec;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, _; cin >> n >> m >> _;
    int tot = 0;
    srand(7122);
    for (int i = 1; i <= n; ++i) r[i] = rand() % maxxor;
    int asd = 0;
    while (m--) {
        int a, b, c; cin >> a >> b >> c; asd += c;
        vec.push_back(make_pair(r[a] ^ r[b], c));
    }
    for (auto p : vec) tot ^= p.first;
    fill(dp[0], dp[0] + (maxxor << 1), inf); fill(dp[1], dp[1] + (maxxor << 1), inf);
    dp[0][0] = dp[1][0] = 0;
    int cur = 0;
    for (auto p : vec) {
        for (int i = maxxor; i >= 0; --i) {
            dp[cur][i ^ p.first] = min(dp[cur ^ 1][i ^ p.first], dp[cur ^ 1][i] + p.second);
        }
        cur ^= 1;
    }
    cout << dp[cur ^ 1][tot] + asd << endl;
    return 0;
}

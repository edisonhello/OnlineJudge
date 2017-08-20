#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, inf = 1e9 + 1;
int dp[2][4][4][maxn], t[2][maxn];

inline int get(char c) {
    return (c == 'M' ? 1 : c == 'F' ? 2 : 3);
}

int count(int a, int b, int c) {
    set<int> s; s.insert(a); s.insert(b); s.insert(c);
    return (int)s.size();
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    string s; cin >> s; s = "." + s;
    for (int i = 0; i < 2; ++i) for (int j = 0; j < 4; ++j) for (int k = 0; k < 4; ++k) for (int l = 0; l < maxn; ++l) dp[i][j][k][l] = -inf;
    for (int i = 0; i < 2; ++i) for (int j = 0; j < maxn; ++j) t[i][j] = -inf;
    dp[0][0][0][0] = dp[1][0][0][0] = 0; t[0][0] = t[1][0] = 0;
    for (int i = 1; i <= n; ++i) {
        int id = get(s[i]);
        for (int j = 0; j < 2; ++j) {
            dp[j][0][id][i] = 1 + t[j ^ 1][i - 1];
            if (i >= 2) for (int k = 0; k <= 3; ++k) {
                int p = i - 2;
                if (k) --p;
                if (p < 0) continue;
                dp[j][1][id][i] = max(dp[j][1][id][i], dp[j][k][1][i - 1] + count(1, id, k) + t[j ^ 1][p]);
                dp[j][2][id][i] = max(dp[j][2][id][i], dp[j][k][2][i - 1] + count(2, id, k) + t[j ^ 1][p]);
                dp[j][3][id][i] = max(dp[j][3][id][i], dp[j][k][3][i - 1] + count(3, id, k) + t[j ^ 1][p]);
            }
            for (int k = 0; k <= 3; ++k) for (int l = 0; l <= 3; ++l) t[j][i] = max(t[j][i], dp[j][k][l][i]);
        }
    }
    cout << max(t[0][n], t[1][n]) << endl;
    return 0;
}

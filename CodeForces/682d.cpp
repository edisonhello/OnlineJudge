#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, p = 131, inf = 1e9 + 1;
string s, t;
int dp[11][maxn][maxn];
unsigned long long ppow[maxn], hashs[maxn], hasht[maxn];

void init();
int f(int, int, int, bool);
bool check(int, int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    cin >> s >> t; s = "." + s; t = "," + t;
    init();
    cout << f(k, n, m, true) << endl;
}

void init() {
    ppow[0] = 1; hashs[0] = s[0]; hasht[0] = t[0];
    for (int i = 1; i < maxn; ++i) {
        ppow[i] = ppow[i - 1] * p;
        if (i < s.length()) hashs[i] = (hashs[i - 1] * p + s[i]);
        if (i < t.length()) hasht[i] = (hasht[i - 1] * p + t[i]);
    }
}

int f(int k, int n, int m, bool ok) {
    if (k == 0) return 0;
    if (n == 0 || m == 0) {
        if (k == 0) return 0;
        return -inf;
    }
    if (dp[k][n][m]) return dp[k][n][m];
    if (s[n] == t[m]) {
        dp[k][n][m] = max({ f(k, n - 1, m, ok), f(k, n, m - 1, ok) });
    } else {
        dp[k][n][m] = max({ f(k, n - 1, m, false), f(k, n, m - 1, false) });
    }
    return dp[k][n][m];
}

bool check(int la, int ra, int lb, int rb) {
    unsigned long long h1 = (la == 0 ? hashs[ra] : hashs[ra] - ppow[ra - la + 1] * hashs[la - 1]);
    unsigned long long h2 = (lb == 0 ? hasht[rb] : hasht[rb] - ppow[rb - lb + 1] * hasht[lb - 1]);
    return h1 == h2;
}

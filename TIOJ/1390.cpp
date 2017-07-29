#include <bits/stdc++.h>
using namespace std;

const int maxn = 15;
int mem[1 << maxn], t[2][maxn][maxn], n;

int dp(int);

int main() {
    while (cin >> n) {
        memset(mem, 0, sizeof(mem));
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> t[0][i][j];
        for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) cin >> t[1][i][j];
        cout << dp((1 << n) - 1) << endl;
    }
    return 0;
}

int dp(int s) {
    if (s == 0) return 0;
    if (mem[s]) return mem[s];
    for (int i = 0; i < n; ++i) if (s & (1 << i)) for (int j = i + 1; j < n; ++j) {
        if ((1 << j) & s) {
            int l = t[1][i][j] == j ? i : j;
            mem[s] = max(mem[s], dp(s ^ (1 << l)) + t[0][i][j]);
        }
    }
    return mem[s];
}

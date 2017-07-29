#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 16;
int t[maxn], n;
long long mem[maxn][1 << maxn];

long long dp(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> t[i];
    long long ans = LLONG_MAX;
    memset(mem, 0, sizeof(mem));
    for (int i = 0; i < n; ++i) ans = min(ans, dp(i, ((1 << n) - 1) ^ (1 << i)));
    cout << ans << endl;
    return 0;
}

long long dp(int x, int s) {
    if (s == 0) {
        int ti = x + 1;
        if (ti % (long long)t[x] == 0) return ti;
        return (long long)t[x] * (ti / (long long)t[x] + 1);
    }
    if (mem[x][s]) return mem[x][s];
    mem[x][s] = LLONG_MAX;
    for (int i = 0; i < n; ++i) if ((1 << i) & s) {
        long long ti = dp(i, s ^ (1 << i)) + abs(x - i);
        if (ti % (long long)t[x] == 0) mem[x][s] = min(mem[x][s], ti);
        else mem[x][s] = min(mem[x][s], (long long)t[x] * (ti / (long long)t[x] + 1));
    }
    return mem[x][s];
}

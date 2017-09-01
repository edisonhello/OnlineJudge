#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, mod = 1e9 + 7;
int dp[4][4][maxn];

int add(int a, int b) { return a += b >= mod ? a - mod : a; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    string s; cin >> s;
    if (s.length() == 1) {
        int ans;
        if (s == "?") ans = 2;
        if (s == "1" || s == "2") ans = 0;
        if (s == "*" || s == "0") ans = 1;
        return cout << ans << endl, 0;
    }

}

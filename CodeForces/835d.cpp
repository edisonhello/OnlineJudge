#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10, lg = 13, mod[3] = { 370248451, 39916801, 479001599 }, p[3] = {  149, 719, 167 };
bool pal[2][maxn][maxn];
unsigned long long h[3][2][maxn], pp[3][maxn], ans[maxn];
string s;
inline bool check(int ss, int l, int r) {
    unsigned long long h1, h2;
    if (l == 0) h1 = h[ss][0][r];
    else h1 = h[ss][0][r] - pp[ss][r - l + 1] * h[ss][0][l - 1];
    if (r == s.length() - 1) h2 = h[ss][1][l];
    else h2 = h[ss][1][l] - pp[ss][r - l + 1] * h[ss][1][r + 1];
    return h1 == h2;
}
inline bool ccheck(int l, int r) {
    for (int i = 0; i < 1; ++i) {
        int seed = rand() % 2;
        if (!check(seed, l, r)) return false;
    }
    return true;
}
inline bool ossas(int s, int l1, int r1, int l2, int r2) {
    if (r1 - l1 + 1 <= 0 || r2 - l2 + 1 <= 0) return true;
    unsigned long long h1, h2;
    if (l1 == 0) h1 = h[s][0][r1];
    else h1 = h[s][0][r1] - pp[s][r1 - l1 + 1] * h[s][0][l1 - 1];
    if (l2 == 0) h2 = h[s][0][r2];
    else h2 = h[s][0][r2] - pp[s][r2 - l2 + 1] * h[s][0][l2 - 1];
    return h1 == h2;
}

inline bool osas(int l1, int r1, int l2, int r2) {
    for (int i = 0; i < 1; ++i) {
        int seed = rand() % 2;
        if (!ossas(seed, l1, r1, l2, r2)) return false;
    }
    return true;
}

int main() {
    // int sd = time(nullptr);
    srand(1501518028);
    // cout << sd << endl;
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> s;
    pp[0][0] = pp[1][0] = 1LL; 
    for (int s = 0; s < 2; ++s) for (int i = 1; i < maxn; ++i) pp[s][i] = (pp[s][i - 1] * p[s]);
    h[0][0][0] = h[1][0][0] = s[0]; 
    for (int ss = 0; ss < 2; ++ss) for (int i = 1; i < s.length(); ++i) h[ss][0][i] = (h[ss][0][i - 1] * p[ss] + s[i]);
    // h[0][1][s.length() - 1] = h[1][1][s.length() - 1] = s[s.length() - 1];
    // for (int ss = 0; ss < 2; ++ss) for (int i = s.length() - 2; i >= 0; --i) h[ss][1][i] = (h[ss][1][i + 1] * p[ss] + s[i]);
    // for (int i = 0; i < s.length(); ++i) {
        // for (int j = i; j < s.length(); ++j) if (ccheck(i, j)) ++ans[1], pal[0][i][j] = true;
    // }
    int cur = 1;
    for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) pal[0][i][j] = true;
    for (int _ = 1; ; ++_) {
        if ((1 << (_ - 1)) > s.length()) break;
        for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) pal[cur][i][j] = false;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                int len = j - i + 1;
                if (!pal[cur ^ 1][i][i + len / 2 - 1] || !pal[cur ^ 1][j - len / 2 + 1][j]) continue;
                if (osas(i, i + len / 2 - 1, j - len / 2 + 1, j)) {
                    ++ans[_];
                    pal[cur][i][j] = true;
                }
            }
        }
        cur ^= 1;
    }
    for (int i = 1; i <= s.length(); ++i) {
        if ((1 << (i - 1) > s.length())) cout << 0 << ' ';
        else cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}

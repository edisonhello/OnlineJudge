#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5, sigma = 26;
int cnt[maxn][sigma];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        for (int j = 0; j < s.length(); ++j) cnt[i][s[j] - 'a']++;
    }
    for (int i = 0; i < sigma; ++i) {
        int Min = maxn + 1;
        for (int j = 0; j < n; ++j) Min = min(Min, cnt[j][i]);
        while (Min--) cout << (char)(i + 'a');
    }
    return 0;
}

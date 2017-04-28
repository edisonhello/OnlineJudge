#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 5;
string s[maxn];
int diff;
bool same;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) cin >> s[i];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i + 1 < n) {
                if (s[i + 1][j] != s[i][j]) ++diff;
                else same = true;
            }   
            if (j + 1 < m) {
                if (s[i][j + 1] != s[i][j]) ++diff;
                else same = true;
            }
        }
    }
    cout << diff + (int)same << '\n';
    return 0;
}

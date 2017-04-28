#include <bits/stdc++.h>
using namespace std;

const int maxn = 25 + 5, sigma = 26;
string s[maxn];
vector<pair<int, int>> pos[sigma];

bool check(int, int, int, int, int);
void solve(int, int, int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t, kase = 0; cin >> t; while (t--) {
        cout << "Case #" << ++kase << ": \n";
        int r, c; cin >> r >> c;
        for (int i = 0; i < r; ++i) cin >> s[i];
        fill(pos, pos + sigma, vector<pair<int, int>>());
        for (int i = 0; i < r; ++i) for (int j = 0; j < c; ++j) {
            if (s[i][j] != '?') pos[s[i][j] - 'A'].push_back(make_pair(i, j));
        }
        for (int i = 0; i < sigma; ++i) if (pos[i].size()) {
            bool done = false;
            for (int r1 = 0; r1 < r && !done; ++r1) for (int r2 = r - 1; r2 >= r1 && !done; --r2) {
                for (int c1 = 0; c1 < c && !done; ++c1) for (int c2 = c - 1; c2 >= c1 && !done; --c2) {
                    if (check(r1, r2, c1, c2, i)) solve(r1, r2, c1, c2, i), done = true;
                }
            }
        }
        for (int i = 0; i < r; ++i) cout << s[i] << '\n';
    }
    return 0;
}

bool check(int r1, int r2, int c1, int c2, int n) {
    for (auto i : pos[n]) {
        if (i.first < r1 || i.first > r2 || i.second < c1 || i.second > c2) return false;
    }
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) if (s[i][j] != '?' && s[i][j] != (char)(n + 'A')) return false;
    }
    return true;
}

void solve(int r1, int r2, int c1, int c2, int n) {
    for (int i = r1; i <= r2; ++i) {
        for (int j = c1; j <= c2; ++j) s[i][j] = (char)(n + 'A');
    }
}

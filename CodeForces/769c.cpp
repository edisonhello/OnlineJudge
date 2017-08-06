#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
const int dx[] = {1, 0, 0, -1}, dy[] = {0, -1, 1, 0};
string s[maxn];

char get(int i) {
    if (i == 0) return 'D';
    if (i == 1) return 'L';
    if (i == 2) return 'R';
    if (i == 3) return 'U';
}

char rev(int i) {
    if (i == 0) return 'U';
    if (i == 1) return 'R';
    if (i == 2) return 'L';
    if (i == 3) return 'D';
}

int cnt[4];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    if (k & 1) return cout << "IMPOSSIBLE" << endl, 0;
    for (int i = 0; i < n; ++i) cin >> s[i];
    int x = -1, y = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) if (s[i][j] == 'X') x = i, y = j;
    }
    vector<int> vec;
    for (int i = 0; i < k / 2; ++i) {
        bool ok = false;
        for (int j = 0; j < 4; ++j) if (x + dx[j] >= 0 && x + dx[j] < n && y + dy[j] >= 0 && y + dy[j] < m) {
            if (s[x + dx[j]][y + dy[j]] == '.' || s[x + dx[j]][y + dy[j]] == 'X') {
                ok = true;
                x += dx[j]; y += dy[j];
                vec.push_back(j);
                break;
            }
        }
        if (!ok) return cout << "IMPOSSIBLE" << endl, 0;
    }
    for (int i : vec) ++cnt[i];
    for (int i = 0; i < k / 2; ++i) {
        bool ok = false;
        for (int j = 0; j < 4; ++j) if (x + dx[j] >= 0 && x + dx[j] < n && y + dy[j] >= 0 && y + dy[j] < m) {
            if ((s[x + dx[j]][y + dy[j]] == '.' || s[x + dx[j]][y + dy[j]] == 'X') && cnt[3 - j] > 0) {
                cnt[3 - j]--;
                ok = true;
                x += dx[j]; y += dy[j];
                vec.push_back(j);
                break;
            }
        }
    }
    for (int i : vec) cout << get(i); cout << endl;
    return 0;
}

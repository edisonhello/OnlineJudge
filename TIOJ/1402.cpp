#include <bits/stdc++.h>
using namespace std;

const int maxn = 500 + 5;
const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
int p[maxn][maxn], n, m, low, cnt;
bool v[maxn][maxn];

bool check(int, int);
void dfs(int, int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    while (cin >> n >> m) {
        memset(p, -1, sizeof(p)); memset(v, false, sizeof(v));
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) cin >> p[i][j];
        int ans = 0;
        for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) {
            if (!v[i][j]) {
                low = INT_MAX; cnt = 0;
                dfs(i, j, p[i][j]);
                if (low > p[i][j]) ans += low * cnt;
            }
        }
        cout << ans << endl;
    }
    return 0;
}

void dfs(int x, int y, int h) {
    ++cnt;
    v[x][y] = true;
    for (int i = 0; i < 4; ++i) if (check(x + dx[i], y + dy[i])) {
        if (p[x + dx[i]][y + dy[i]] != p[x][y]) low = min(low, p[x + dx[i]][y + dy[i]]);
    }
    for (int i = 0; i < 4; ++i) if (check(x + dx[i], y + dy[i])) {
        if (!v[x + dx[i]][y + dy[i]]) if (p[x + dx[i]][y + dy[i]] <= h) dfs(x + dx[i], y + dy[i], h);
    }
}

bool check(int x, int y) {
    return x >= 0 && x <= n+ 1 && y <= m + 1 && y >= 0;
}

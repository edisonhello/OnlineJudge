#include <iostream>
#include <vector>
#include <cstring>
#define lowbit(x) (x & -x)
using namespace std;

struct Point {
  int x, y;
};

const int maxn = 1000 + 5, MOD = 1000000007;
int BIT[maxn][maxn], ans[maxn][maxn], R, C, T, x, ret;
vector<Point> v[maxn];

int query(int, int);
void modify(int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> T;
  while (T--) {
    cin >> R >> C;
    memset(BIT, 0, sizeof(BIT));
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < maxn; ++i) v[i].clear();
    for (int i = 1; i <= R; ++i) for (int j = 1; j <= C; ++j) {
      cin >> x;
      v[x].push_back((Point){ i, j });
    }
    for (int i = 0; i < maxn; ++i) if (v[i].size()) {
      for (auto u : v[i]) ans[u.x][u.y] = 1 + query(u.x, u.y);
      for (auto u : v[i]) modify(u.x, u.y, ans[u.x][u.y]);
    }
    ret = 0;
    for (int i = 1; i <= R; ++i) for (int j = 1; j <= C; ++j) ret += ans[i][j], ret %= MOD;
    cout << ret << '\n';
  }
  return 0;
}

int query(int x, int y) {
  int ret = 0;
  for (int i = x; i; i -= lowbit(i)) for (int j = y; j; j -= lowbit(j)) ret += BIT[i][j], ret %= MOD;
  return ret;
}

void modify(int x, int y, int v) {
  for (int i = x; i < maxn; i += lowbit(i)) for (int j = y; j < maxn; j += lowbit(j)) BIT[i][j] += v, BIT[i][j] %= MOD;
}

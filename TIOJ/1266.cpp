#include <bits/stdc++.h>
#define lowbit(x) (x & -x)
using namespace std;

const int maxn = 1000 + 5;
struct Point { int x, y; } p[maxn * maxn];
int N, v, BIT[maxn][maxn], ans[maxn][maxn];

int dp(int, int);
void add(int, int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) {
    cin >> v;
    p[v] = (Point){ i, j };
  }
  for (int i = 1; i <= N * N; ++i) {
    ans[p[i].x][p[i].y] = dp(p[i].x, p[i].y) + 1;
    add(p[i].x, p[i].y, ans[p[i].x][p[i].y]);
  }
  int Max = 0;
  for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j) Max = max(Max, ans[i][j]);
  cout << Max << '\n';
  return 0;
}

int dp(int x, int y) {
  int ret = 0;
  while (x) {
    for (int i = y; i; i -= lowbit(i)) ret = max(ret, BIT[x][i]);
    x -= lowbit(x);
  }
  return ret;
}

void add(int x, int y, int v) {
  while (x <= N) {
    for (int i = y; i <= N; i += lowbit(i)) BIT[x][i] = max(BIT[x][i], v);
    x += lowbit(x);
  }
}

#include <bits/stdc++.h>
using namespace std;

const int maxn = 10 + 5;
const int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int n, S, x, y, mat[maxn][maxn], dp[maxn][maxn][maxn], Max;
struct Osas { int x, y, tot, s; };
bool v[maxn][maxn];

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n >> S;
  for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) cin >> mat[i][j];
  cin >> x >> y, ++x, ++y;
  for (int i = 0; i < maxn; ++i) for (int j = 0; j < maxn; ++j) for (int k = 0; k < maxn; ++k) dp[i][j][k] = -1;
  dp[0][y][x] = 0;
  for (int s = 1; s <= S; ++s) {
    for (int i = 1; )
  }
  cout << Max << '\n';
  return 0;
}

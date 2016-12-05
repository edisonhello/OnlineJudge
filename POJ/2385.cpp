#include <cstdio>
#include <algorithm>
using namespace std;

int dpa[31][1005], T, W;
short tree[1005];
bool v[31][1005];
int dp(int, int, int);

int main() {
  scanf("%d %d", &T, &W);
  for (int i = 1; i <= T; ++i) scanf("%hi", tree + i);
  for (int i = 1; i <= T; ++i) {
    for (int w = 0; w <= i; ++w) {
      if (dp[w][i] = max(dp[w + 1])
    }
  }
  printf("%d\n", max(dp(1, W, T), dp(2, W, T)));
}

int dp(int id, int w, int t) {
  if (t < 0) return 0;
  if (w < 0) return 0;
  if (v[w][t]) return dpa[w][t];
  if (id == tree[T]) dpa[w][t] = max(dp(id == 1 ? 2 : 1, w - 1, t - 1), dp(id, w, t - 1) + 1);
  else dpa[w][t] = max(dp(id == 1 ? 2 : 1, w - 1, t - 1) + 1, dp(id, w, t - 1));
  return dpa[w][t];
}

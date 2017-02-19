#include <bits/stdc++.h>
using namespace std;

const int maxn = 800 + 5;
struct Point { int x, y; } p[maxn];
double dp[maxn][maxn];
bool v[maxn][maxn];
int N, tx, ty;

inline double dis(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> N;
  for (int i = 0; i < N; ++i) cin >> p[i].x >> p[i].y;=, tx += p[i].x, ty += p[i].y;
  tx /= N; ty /= N;
  sort(p, p + N, [](const Point& a, const Point& b) -> bool {
    return atan((a.y - ty) / (a.x - tx)) < atan((b.y - ty) / (b.x - tx));
  });
  DP(0, N - 1);
  return 0;
}

double DP(int L, int R) {
  if (v[L][R]) return dp[L][R];
  dp[L][R] = (1<<40);
  for (int i = L + 1; i < R; ++i) {
    dp[L][R] = min(dp[L][R], DP(L, i) + DP(k, R) + dis(L, R));
  }
  return dp[L][R];
}

inline double dis(int a, int b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

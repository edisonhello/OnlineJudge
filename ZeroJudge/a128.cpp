#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 15;
const int maxw = 100 + 5;

bool dpa[1 << maxn][maxw], v[1 << maxn][maxw];
int sum[1 << maxn], A[maxn], N, x, y, kase;
bool dp(int, int);
int bit(int);

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  while (cin >> N, N) {
    memset(dpa, false, sizeof(dpa));
    memset(sum, 0, sizeof(sum));
    memset(v, false, sizeof(v));
    cin >> x >> y;
    for (int i = 0; i < N; ++i) cin >> A[i];
    for (int s = 0; s < (1 << N); ++s) {
      for (int i = 0; i < N; ++i) if (s & (1 << i)) sum[s] += A[i];
    }
    bool ans;
    if (sum[(1 << N) - 1] != x * y || sum[(1 << N) - 1] % x) ans = false;
    else ans = dp((1 << N) - 1, min(x, y));
    cout << "Case " << ++kase << ": ";
    cout << (ans ? "Yes\n" : "No\n");
  }
  return 0;
}

bool dp(int S, int x) {
  if (v[S][x]) return dpa[S][x];
  if (bit(S) == 1) return dpa[S][x] = true;
  v[S][x] = true;
  int y = sum[S] / x;
  for (int s = (S - 1) & S; s; s = (s - 1) & S) {
    if (sum[s] % x == 0 && dp(s, min(x, sum[s] / x)) && dp(S - s, min(x, sum[S - s] / x))) return dpa[S][x] = true;
    if (sum[s] % y == 0 && dp(s, min(y, sum[s] / y)) && dp(S - s, min(y, sum[S - s] / y))) return dpa[S][x] = true;
  }
  return dpa[S][x] = false;
}

int bit(int x) { return x == 0 ? 0 : bit(x >> 1) + (x & 1); }

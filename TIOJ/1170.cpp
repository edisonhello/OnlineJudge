#include <cstdio>
#include <algorithm>
#include <bitset>
#include <vector>
#define INF (1 << 30)
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
  __c = 0; flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) {return rit(x) && rit(args...);}

int N, a, sm[1005], dp[1005][1005], h[1005][1005];
vector<bitset<1005>> v(1005);
int dpdp(int, int);

int main() {
  rit(N);
  for (int i = 0; i < N; ++i) rit(a), sm[i + 1] = sm[i] + a;
  printf("%d\n", dpdp(0, N - 1));
}

int dpdp(int L, int R) {
  if (L >= R) return 0;
  if (v[L][R]) return dp[L][R];
  int mx = -INF;
  for (int k = L; k < R; ++k) {
    mx = max(mx, max(dpdp(L, k), dpdp(k + 1, R)) + (sm[R + 1] - sm[k + 1]) * (sm[k + 1] - sm[L]));
  }
  v[L][R] = true;
  return dp[L][R] = mx;
}

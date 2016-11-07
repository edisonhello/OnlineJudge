#include <cstdio>
#include <vector>
#include <cstring>
#define getchar getchar_unlocked
#define MOD 1073741824
using namespace std;

char __c;
bool flag;

template <typename T>
inline bool rit(T& x) {
  __c = 0, flag = false;
  while (__c = getchar(), (__c < '0' && __c != '-') || __c > '9') if (__c == -1) return false;
  __c == '-' ? (flag = true, x = 0) : (x = __c - '0');
  while (__c = getchar(), __c >= '0' && __c <= '9') x = x * 10 + __c - '0';
  if (flag) x = -x;
  return true;
}

template <typename T, typename ...Args>
inline bool rit(T& x, Args& ...args) { return rit(x) && rit(args...); }

vector<int> G[10005];
int N, M, A, B, V, D, dpa[10005], tot;
bool v[10005];
int dp(int);

int main() {
  rit(N, M);
  for (int i = 0; i < M; ++i) {
    rit(A, B);
    G[A].push_back(B);
  }
  rit(V, D);
  memset(dpa, -1, sizeof(dpa));
  dpa[D] = 1;
  printf("%d\n", dp(V));
  return 0;
}

int dp(int x) {
  if (dpa[x] != -1) return dpa[x];
  int& ans = dpa[x]; ans = 0;
  v[x] = true;
  for (auto i : G[x]) {
    if (!v[i]) ans = (ans + dp(i)) % MOD;
  }
  v[x] = false;
  return ans;
}

#include <cstdio>
#include <vector>
#include <cstring>
#define getchar getchar_unlocked
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

int dpa[1005], N, T, w[1005], K, x, in[1005], ans;
vector<int> G[1005];
int dp(int);

int main() {
  rit(T);
  while (T--) {
    rit(N);
    for (int i = 1; i <= N; ++i) G[i].clear();
    for (int i = 1; i <= N; ++i) {
      rit(w[i], in[i]);
      for (int j = 0; j < in[i]; ++j) rit(x), G[x].push_back(i);
    }
    memset(dpa, 0, sizeof(dpa)); ans = 0;
    for (int i = 1; i <= N; ++i) {
      if (in[i] == 0) ans = max(ans, dp(i));
    }
    printf("%d\n", ans);
  }
  return 0;
}

int dp(int x) {
  if (dpa[x]) return dpa[x];
  if (!G[x].size()) return w[x];
  for (auto i : G[x]) {
    dpa[x] = max(dpa[x], dp(i) + w[x]);
  }
  return dpa[x];
}

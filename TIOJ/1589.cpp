#include <cstdio>
#include <unordered_map>
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

int v, e, m, a, b, dpa[250], s, t;
unordered_map<int, int> G[250];
bool V[250];
int dp(int);

int main() {
  rit(v, e, m);
  while (e--) {
    rit(a, b);
    G[a][b]++;
  }
  rit(s, t);
  printf("%d\n", dp(s) % m);
  return 0;
}

int dp(int x) {
  if (V[x]) return dpa[x];
  if (x == t) return 1;
  for (auto i : G[x]) {
    dpa[x] += i.second * dp(i.first);
    dpa[x] %= m;
  }
  V[x] = true;
  return dpa[x];
}

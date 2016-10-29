#include <cstdio>
#include <set>
#include <algorithm>
// #ifdef linux
#define getchar getchar_unlocked
// #endif
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
inline bool rit(T& x, Args& ...args) {return rit(x) && rit(args...);}

int n, c, tot, degree[10005], tp1, tp2;
bool p;
bool check();

int main() {
  while (rit(n), n) {
    tot = 0; p = true;
    for (int i = 0; i < n; ++i) rit(degree[i]), tot += degree[i];
    if (tot & 1) { printf("No\n"); continue; }
    sort(degree, degree + n, [](const int& a, const int& b) -> bool {return a > b;});
    if (check()) printf("Yes\n");
    else printf("No\n");
  }
  return 0;
}

bool check() {
  for (int i = 0; i < n; ++i) {
    tp1 = 0, tp2 = 0;
    for (int j = 0; j <= i; ++j) tp1 += degree[j];
    for (int j = i + 1; j < n; ++j) tp2 += min(i + 1, degree[j]);
    if (tp1 > i * (i + 1) + tp2) return false;
  }
  return true;
}

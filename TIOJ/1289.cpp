#include <cstdio>
#include <algorithm>
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

bool check(int, int, int);
int n, edge[2005], cnt;

int main() {
  while (rit(n)) {
    for (int i = 0; i < n; ++i) rit(edge[i]);
    sort(edge, edge + n);
    cnt = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          if (check(edge[i], edge[j], edge[k])) cnt++;
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}

bool check(int a, int b, int c) {
  return c * c == a * a + b * b;
}

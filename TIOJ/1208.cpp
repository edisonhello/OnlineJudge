#include <cstdio>
#define INF 1000000000
#define getchar getchar_unlocked
using namespace std;

int n, k, a[20010], b[20010], mx[20010], mn[20010], s[20010], lb, rb, m, cnt, ans, __t, __k;
char __c;

inline int rit() {
  __t = 0, __k = 1;
  do {
    __c = getchar();
    if (__c == '-') __k = -1;
  } while (__c < '0' || __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar();
  } while (__c >= '0' && __c <= '9');
  return __t * __k;
}

void merge(int l, int r) {
  if (l == r) return;
  int mid = (l + r) >> 1;
  merge(l, mid), merge(mid + 1, r);
  int i = l; int c = l; int p = l;
  for (int j = mid + 1; j <= r; ++j) {
    while (i <= mid && s[i] <= s[j]) a[c++] = s[i++];
    while (p <= mid && s[j] - s[p] > m) p++;
    a[c++] = s[j];
    cnt += p - l;
  }
  while (i <= mid) a[c++] = s[i++];
  for (i = l; i <= r; ++i) s[i] = a[i];
}

int main() {
  while (true) {
    n = rit(), k = rit();
    if (n == 0 && k == 0) break;
    lb = INF, rb = -INF;
    b[0] = 0, mx[0] = 0, mn[0] = 0;
    for (int i = 0; i < n; ++i) {
      a[i] = rit();
      b[i + 1] = b[i] + a[i];
      mx[i + 1] = mx[i] > 0 ? mx[i] + a[i] : a[i];
      mn[i + 1] = mn[i] < 0 ? mn[i] + a[i] : a[i];
      if (mx[i + 1] > rb) rb = mx[i + 1];
      if (mn[i + 1] < lb) lb = mn[i + 1];
    }
    while (lb <= rb) {
      m = (lb + rb) / 2;
      for (int i = 0; i <= n; ++i) s[i] = b[i];
      cnt = 0;
      merge(0, n);
      if (cnt < k) rb = m - 1, ans = m;
      else lb = m + 1;
    }
    printf("%d\n", ans);
  }
}

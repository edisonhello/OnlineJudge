#include <iostream>
#include <algorithm>
#define getchar getchar_unlocked
using namespace std;

struct B {
  int p[51], u[51], l[51], idx;
};

int n, k;
B b[51];
int s1[51], s2[51], mx1, mx2;
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

bool beat(int i, int j) {
  int win = 0;
  int ii = 0, iii = 2 * k + 1;
  int jj = 0, jjj = 2 * k + 1;
  while (ii < iii && jj < jjj) {
    if (b[i].p[ii] > b[j].p[jj]) ii++, jj++, win++;
    else if (b[i].p[ii] < b[j].p[jj]) iii--, jj++;
    else {
      if (b[i].idx < b[j].idx) ii++, jj++, win++;
      else iii--, jj++;
    }
  }
  return win >= k + 1;
}

bool beat2(int i, int j) {
  int win = 0;
  int ii = 0, iii = 2 * k + 1;
  int jj = 0, jjj = 2 * k + 1;
  while (ii < iii && jj < jjj) {
    if (b[i].u[ii] > b[j].l[jj]) ii++, jj++, win++;
    else if (b[i].u[ii] < b[j].l[jj]) iii--, jj++;
    else {
      if (b[i].idx < b[j].idx) ii++, jj++, win++;
      else iii--, jj++;
    }
  }
  return win >= k + 1;
}

int main() {
  rit(k, n);
  for (int i = 0; i < n; ++i) {
    rit(b[i].idx);
    for (int j = 0; j < 2 * k + 1; ++j) rit(b[i].p[j]);
    for (int j = 0; j < 2 * k + 1; ++j) rit(b[i].u[j]);
    for (int j = 0; j < 2 * k + 1; ++j) rit(b[i].l[j]);
  }
  for (int i = 0; i < n; ++i) s1[i] = i;
  for (int i = 0; i < n; ++i) s2[i] = i;
  mx1 = 0;
  for (int i = 0; i < n; ++i) {
    bool p = true;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (!beat(i, j)) {p = false; break;}
    }
    if (p) if (b[i].idx > mx1) mx1 = b[i].idx;
  }
  mx2 = 0;
  for (int i = 0; i < n; ++i) {
    bool p = true;
    for (int j = 0; j < n; ++j) {
      if (i == j) continue;
      if (!beat2(i, j)) {p = false; break;}
    }
    if (p) if (b[i].idx > mx2) mx2 = b[i].idx;
  }
  printf("%d %d\n", mx1, mx2);
  return 0;
}

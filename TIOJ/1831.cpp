#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <cstdio>
#define getchar getchar_unlocked
using namespace std;

short n, m, k, a, b, __t, i, j;
char __c;
void one();
void zero();
string s;

inline short rit() {
  __t = 0;
  do {
    __c = getchar();
  } while (__c < '0' || __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar();
  } while (__c >= '0' && __c <= '9');
  return __t;
}

int main() {
  n = rit(), m = rit(), k = rit();
  if (k == 0) zero();
  else one();
  return 0;
}

void zero() {
  bool mm[101][101];
  memset(mm, false, sizeof(mm));
  for (i = 0; i < m; ++i) {
    a = rit(), cin >> s, b = rit();
    if (s[0] == '-') mm[a - 1][b - 1] = true;
    else mm[b - 1][a - 1] = true;
  }
  for (i = 0; i < n; ++i) {
    for (j = 0; j < n; ++j) {
      if (mm[i][j]) printf("1 ");
      else printf("0 ");
    }
    printf("\n");
  }
}

void one() {
  set<short> mm[101];
  for (i = 0; i < n; ++i) {
    a = rit(); cin >> s; b = rit();
    if (s[0] == '-') mm[a].insert(b);
    else mm[b].insert(a);
  }
  for (i = 1; i <= n; ++i) {
    printf("%d ->", i);
    if (mm[i].size()) {
      for (set<short>::iterator it = mm[i].begin(); it != mm[i].end(); ++it) {
        printf(" %d", *it);
      }
    } else {
      printf(" 0");
    }
    printf("\n");
  }
}

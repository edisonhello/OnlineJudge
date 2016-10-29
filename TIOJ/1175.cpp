#include <cstdio>
#include <algorithm>
#include <vector>
#define getchar getchar_unlocked
using namespace std;

vector<int> v;
int n, x, __t;
char __c;
int LIS();

inline int rit() {
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
  n = rit();
  for (int i = 0; i < n; ++i) x = rit(), v.push_back(x);
  printf("%d\n", LIS());
  return 0;
}

int LIS() {
  vector<int> vv;
  vv.push_back(v[0]);
  for (int i = 1; i < n; ++i) {
    if (v[i] > vv.back()) vv.push_back(v[i]);
    else *lower_bound(vv.begin(), vv.end(), v[i]) = v[i];
  }
  return vv.size();
}

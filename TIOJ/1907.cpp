#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define getchar getchar_unlocked
using namespace std;

struct Doll {
  int w, h;
  Doll(int w, int h): w(w), h(h) {}
  Doll() {}
};

int n, m, w, h, __t, __k, i;
char __c;
inline int rit();
long long LIS(vector<Doll>);
Doll tmp;

vector<Doll> vec;

bool cmp(const Doll& a, const Doll& b) {
  return a.w == b.w ? a.h > b.h : a.w < b.w;
}

bool cmp1(const Doll& a, const Doll& b) {
  return a.w < b.w && a.h < b.h;
}

int main() {
  n = rit();
  while (n--) {
    vec.clear();
    m = rit();
    for (i = 0; i < m; ++i) {
        w = rit(), h = rit();
        vec.push_back(Doll(w, h));
    }
    sort(vec.begin(), vec.end(), cmp);
    printf("%lld\n", LIS(vec));
  }
  return 0;
}

inline int rit(){
  __t = 0, __k = 1;
  do {
    __c = getchar();
    if (__c == '-') __k = -1;
  } while (__c < '0' || __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar();
  } while(__c >= '0' && __c <= '9');
  return __t * __k;
}

long long LIS(vector<Doll> d) {
  if (d.size() == 0) return 0;
  vector<Doll> dd;
  dd.push_back(d[0]);
  for (i = 1; i < d.size(); ++i) {
    tmp = d[i];
    if (dd.back().w < tmp.w && dd.back().h < tmp.h) dd.push_back(tmp);
    else *lower_bound(dd.begin(), dd.end(), tmp, cmp1) = tmp;
  }
  return dd.size();
}

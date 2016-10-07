#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <iostream>
#define pii pair<int, int>
using namespace std;

int __t, __k, n, s, f, mx, cur, cnt;
char __c;

inline int rit() {
  __t = 0; __k = 1;
  do {
    __c = getchar_unlocked();
    if (__c == '-') __k = -1;
  } while (__c < '0' || __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar_unlocked();
  } while (__c >= '0' && __c <= '9');
  return __t * __k;
}

vector<pii> vec;

int main() {
  while (scanf("%d", &n) != EOF) {
    vec.clear();
    for (int i = 0; i < n; ++i) {
      s = rit(), f = rit();
      vec.push_back(pii(s, f));
    }
    sort(vec.begin(), vec.end());
    mx = 0;
    // for (int i = 0; i < n; ++i) cout << vec[i].first << ' ' << vec[i].second << endl;
    for (int i = n - 1; i >= 0; --i) {
      cnt = 0;
      for (int j = i; j >= 0; --j) {
        // cout << "second: " << vec[j].second << "first: " << vec[i].first << endl;
        if (vec[j].second >= vec[i].first) cnt++;
        else break;
      }
      // cout << "cnt: " << cnt << endl;
      if (cnt > mx) mx = cnt;
    }
    printf("%d\n", mx);
  }
  return 0;
}

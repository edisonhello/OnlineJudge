#include <iostream>
#include <deque>
#include <utility>
#include <vector>
#include <cstdio>
using namespace std;

typedef pair<int, long long> pil;
typedef pair<int, int> pii;
int N, M, i, j, __t;
char __c;
long long K, H, __tt;
deque<pil> md, nd;
vector<pii> ans;

inline int __rit() {
  __t = 0;
  do {
    __c = getchar_unlocked();
  } while (__c < '0' || __c > '9');
  do {
    __t = __t * 10 + __c - '0';
    __c = getchar_unlocked();
  } while (__c >= '0' && __c <= '9');
  return __t;
}

inline long long __rlit() {
  __tt = 0;
  do {
    __c = getchar_unlocked();
  } while (__c < '0' || __c > '9');
  do {
    __tt = __tt * 10 + __c - '0';
    __c = getchar_unlocked();
  } while (__c >= '0' && __c <= '9');
  return __tt;
}

int main() {
  N = __rit(), M = __rit(), K = __rlit();
  H = __rlit();
  md.push_back(pil(0, H));
  nd.push_back(pil(0, H));
  j = 0;
  for (i = 1; i < N; ++i) {
    if (i - j == M) j++;
    while (md.size() && i - md.front().first >= M) md.pop_front();
    while (nd.size() && i - nd.front().first >= M) nd.pop_front();
    H = __rlit();
    while (md.size() && md.back().second < H) md.pop_back();
    md.push_back(pil(i, H));
    while (nd.size() && nd.back().second > H) nd.pop_back();
    nd.push_back(pil(i, H));
    if (md.front().second - nd.front().second == K) {
      ans.push_back(pii(j, i));
    }
  }
  j++;
  i--;
  while (i - j >= 1) {
    while (md.size() && md.front().first < j) md.pop_front();
    while (nd.size() && nd.front().first < j) nd.pop_front();
    if (md.front().second - nd.front().second == K) {
      ans.push_back(pii(j, i));
    }
    j++;
  }
  printf("%lu\n", ans.size());
  for (size_t __i = 0; __i < ans.size(); ++__i) printf("%d %d\n", ans[__i].first + 1, ans[__i].second + 1);
  return 0;
}

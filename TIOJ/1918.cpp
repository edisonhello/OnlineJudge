#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#define getchar getchar_unlocked
using namespace std;

struct Point {
  long long x, y, z;
};

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

vector<Point> p;
int N;
long long xxx, yyy, zzz;
bool cmp(const Point&, const Point&);
unsigned long long dis(const Point&, const Point&);
unsigned long long solve(int, int);

int main() {
  rit(N);
  for (int i = 0; i < N; ++i) {
    rit(xxx, yyy, zzz);
    p.push_back({ xxx, yyy, zzz });
  }
  sort(p.begin(), p.end(), cmp);
  printf("%llu\n", solve(0, N - 1));
  return 0;
}

bool cmp(const Point& a, const Point& b) { return a.y < b.y; }

unsigned long long dis(const Point& a, const Point& b) {
  return (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z);
}

unsigned long long solve(int L, int R) {
  unsigned long long mn = 18446744073709551615ull;
  int sz = R - L + 1;
  if (sz <= 3) {
    for (int i = 0; i < sz; ++i) {
      for (int j = 0; j < sz; ++j) {
        if (i == j) continue;
        if (dis(p[i], p[j]) < mn) mn = dis(p[i], p[j]);
      }
    }
    return mn;
  }
  long long mid = p[(L + R) >> 1].y;
  unsigned long long lmn = solve(L, (L + R) >> 1), rmn = solve(((L + R) >> 1) + 1, R);
  unsigned long long cur = min(lmn, rmn);
  long long m = 0;
  for (int i = 0; i < sz; ++i) if (abs(p[L + i].y - mid) <= cur) m = i;
  for (int i = 0; i < m; ++i) {
    for (int j = 1; j <= 20 && i + j < sz; ++j) cur = min(cur, dis(p[L + i], p[L + i + j]));
  }
  return cur;
}

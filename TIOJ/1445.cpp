#include <cstdio>
#include <vector>
#include <algorithm>
#define getchar getchar_unlocked
using namespace std;

const long long INF = 9223372036854775805ll;

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

struct Edge {
  long long st, ed, w;
  bool operator<(const Edge& e) const {
    return w < e.w;
  }
};

long long n, m, djs[1005], node, id, w, mn, a, b, c;
vector<Edge> e;
vector<int> MST;

long long F(long long x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }

void U(long long x, long long y) {
  x = F(x); y = F(y);
  djs[x] = y;
}

int main() {
  rit(n, m); mn = INF;
  for (long long i = 0; i <= n; ++i) djs[i] = i;
  for (long long i = 0; i < m; ++i) {
    rit(a, b, c);
    e.push_back((Edge){ a, b, c });
  }
  sort(e.begin(), e.end());
  node = 1; id = -1; w = 0;
  while (node < n && id < m) {
    ++id;
    if (F(e[id].st) == F(e[id].ed)) continue;
    U(e[id].st, e[id].ed); w += e[id].w; node++;
    MST.push_back(id);
  }
  if (node == n) printf("%lld ", w);
  else { printf("-1 -1\n"); return 0;}
  for (long long idd : MST) {
    id = -1; node = 1; w = 0;
    for (long long i = 0; i <= n; ++i) djs[i] = i;
    while (node < n && id < m) {
      ++id;
      if (id == idd) continue;
      if (F(e[id].st) == F(e[id].ed)) continue;
      U(e[id].st, e[id].ed); w += e[id].w; node++;
    }
    if (node < n) { printf("-1\n"); return 0; }
    mn = min(mn, w);
  }
  if (mn == INF) { printf("-1\n"); return 0; }
  printf("%lld\n", mn);
  return 0;
}

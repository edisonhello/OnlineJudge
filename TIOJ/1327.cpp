#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstdlib>
#define getchar gtx
using namespace std;

char __c;
bool flag;

inline int gtx() {
  const int N = 1048576;
  static char buffer[N];
  static char *p = buffer, *end = buffer;
  if (p == end) {
    if ((end = buffer + fread(buffer, 1, N, stdin)) == buffer) return EOF;
    p = buffer;
  }
  return *p++;
}

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

const int maxn = 100000 + 5;

struct Edge {
  int st, ed, w;
  bool operator<(const Edge& rhs) const {
    return w < rhs.w;
  }
};

vector<Edge> E;
int djs[maxn], T, N, x[maxn], y[maxn];

inline int dis(int, int);
int F(int);
long long Kruskal();

int main() {
  rit(T);
  while (T--) {
    rit(N); E.clear();
    for (int i = 0; i < N; ++i) djs[i] = i;
    for (int i = 0; i < N; ++i) rit(x[i], y[i]);
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        if (x[i] == x[j]) E.push_back((Edge){ i, j, abs(y[i] - y[j]) });
        if (y[i] == y[j]) E.push_back((Edge){ i, j, abs(x[i] - x[j]) });
      }
    }
    sort(E.begin(), E.end());
    printf("%lld\n", Kruskal());
  }
  return 0;
}

int F(int x) { return djs[x] == x ? x : djs[x] = F(djs[x]); }

long long Kruskal() {
  int node = 1;
  long long ret = 0;
  for (auto e : E) {
    if (node == N) break;
    int st = F(e.st), ed = F(e.ed);
    if (st == ed) continue;
    ret += (long long)e.w;
    djs[st] = ed;
    node++;
  }
  return ret;
}

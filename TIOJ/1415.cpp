#include <cstdio>
#include <queue>
#include <bitset>
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

struct S {
  int v, id;
  bool operator<(const S& rhs) const {
    return v < rhs.v;
  }
  bool operator>(const S& rhs) const {
    return v > rhs.v;
  }
};

const int maxn = 5000 + 5;
priority_queue<S, vector<S>, less<S>> pq;
priority_queue<S, vector<S>, greater<S>> qp;
bitset<1000005> v;
int T, N, val, k, id, tot;

int main() {
  while (rit(N)) {
    tot = 0; v.reset(); id = 0;
    while (pq.size()) pq.pop();
    while (qp.size()) qp.pop();
    for (int j = 0; j < N; ++j) {
      rit(k);
      for (int i = 0; i < k; ++i) rit(val), pq.push((S){ val, id }), qp.push((S){ val, id++ });
      while (pq.size() && v[pq.top().id]) pq.pop();
      while (qp.size() && v[qp.top().id]) qp.pop();
      if (!pq.size() || !qp.size()) continue;
      tot += pq.top().v - qp.top().v;
      v[pq.top().id] = true; v[qp.top().id] = true;
      pq.pop(); qp.pop();
    }
    printf("%d\n", tot);
  }
  return 0;
}

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define getchar getchar_unlocked
#define INF (1<<30)
#define int long long
#define endl '\n'
using namespace std;

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
  int from, to, w;
  bool operator>(const Edge& edge) const {
    return w > edge.w;
  }
};

vector<Edge> G[1005];
int d[1005];
int n, m, st, ed, a, b, c;
Edge edge;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
bool v[1005];

signed main() {
  while (rit(n, m, st, ed)) {
    memset(v, false, sizeof(v));
    for (int i = 0; i < 1005; ++i) d[i] = INF, G[i].clear();
    while (m--) {
      rit(a, b, c);
      edge.from = a; edge.to = b; edge.w = c;
      G[a].push_back(edge);
      edge.from = b; edge.to = a; edge.w = c;
      G[b].push_back(edge);
    }
    d[st] = 0;
    pq.push((Edge){st, 0, 0 });
    while (pq.size()) {
      edge = pq.top(), pq.pop();
      if (!v[edge.from]) {
        v[edge.from] = true;
        for (auto i : G[edge.from]) {
          if (d[i.to] > d[i.from] + i.w) {
              d[i.to] = d[i.from] + i.w;
              pq.push((Edge){i.to, 0, d[i.to]});
          }
        }
      }
    }
    if (d[ed] == INF) printf("He is very hot\n");
    else printf("%lld\n", d[ed]);
  }
  return 0;
}

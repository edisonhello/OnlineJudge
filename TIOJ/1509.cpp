#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define getchar getchar_unlocked
#define INF 1000000000
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
  int st, ed, w;
};

struct Node {
  int id, w;
  bool operator>(const Node& node) const {
    return w > node.w;
  }
};

int M, N, P, Q, R;
int d[1000005];
long long ans;
vector<Edge> G[1000005], H[1000005];
priority_queue<Node, vector<Node>, greater<Node>> pq;
bool v[1000005];

int main(int argc, char* argv[]) {
  rit(M, N);
  while (N--) {
    rit(P, Q, R);
    G[P].push_back((Edge){ P, Q, R });
    H[Q].push_back((Edge){ Q, P, R });
  }
  for (int i = 1; i <= M; ++i) d[i] = INF;
  d[1] = 0;
  pq.push((Node){ 1, 0 });
  while (pq.size()) {
    Node node = pq.top(); pq.pop();
    if (!v[node.id]) {
      v[node.id] = true;
      for (auto i : G[node.id]) {
        if (d[i.ed] > d[i.st] + i.w) {
          d[i.ed] = d[i.st] + i.w;
          pq.push((Node){ i.ed, d[i.ed] });
        }
      }
    }
  }
  for (int i = 2; i <= M; ++i) {
    if (d[i] == INF) { puts("0"); return 0; }
    ans += d[i];
  }
  memset(v, false, sizeof(v));
  for (int i = 1; i <= M; ++i) d[i] = INF;
  d[1] = 0;
  pq.push((Node){ 1, 0 });
  while (pq.size()) {
    Node node = pq.top(); pq.pop();
    if (!v[node.id]) {
      v[node.id] = true;
      for (auto i : H[node.id]) {
        if (d[i.ed] > d[i.st] + i.w) {
          d[i.ed] = d[i.st] + i.w;
          pq.push((Node){ i.ed, d[i.ed] });
        }
      }
    }
  }
  for (int i = 2; i <= M; ++i) {
    if (d[i] == INF) { puts("0"); return 0; }
    ans += d[i];
  }
  printf("%lld\n", ans);
  return 0;
}

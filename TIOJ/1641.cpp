#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <iomanip>
#include <cstdio>
#include <cmath>
#define PII pair<int, int>
#define INF 1e9
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
  bool operator > (const Edge& e) const {
    return w < e.w;
  }
};

vector<Edge> G[10010];
int n, m, s, t, a, b, c, mn, lg, x;
double d[10010];
bool v[10010];
Edge tmp, pqe;
priority_queue<Edge, vector<Edge>, greater<Edge>> pq;

void test();
void output(double);

int main() {
  rit(n, m, s, t);
  for (int i = 0; i <= n; ++i) d[i] = INF;
  for (int i = 0; i < m; ++i) {
    rit(a, b, c);
    tmp.from = a;
    tmp.to = b;
    tmp.w = log10(c + 1);
    G[a].push_back(tmp);
  }
  d[s] = 0;
  pqe.from = s;
  pqe.w = 0;
  pq.push(pqe);
  while (!pq.empty()) {
    pqe = pq.top(); pq.pop();
    if (!v[pqe.from]) {
      v[pqe.from] = true;
      for (int i = 0; i < G[pqe.from].size(); ++i) {
        if (!v[G[pqe.from][i].to]) {
          if (d[G[pqe.from][i].to] > d[pqe.from] + G[pqe.from][i].w) {
            d[G[pqe.from][i].to] = d[pqe.from] + G[pqe.from][i].w;
            tmp.from = G[pqe.from][i].to;
            tmp.w = d[G[pqe.from][i].to];
            pq.push(tmp);
          }
        }
      }
    }
  }
  x = (int)(floor(d[t] + 1e-7) + 1e-7);
  d[t] -= x;
  printf("%.2fe+%03d\n", pow(10, d[t]), x);
  return 0;
}

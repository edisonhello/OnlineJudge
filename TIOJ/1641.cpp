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

struct Edge {
  int from, to, w;
  bool operator > (const Edge& e) const {
    return w < e.w;
  }
};

vector<Edge> G[10010];
int n, m, s, t, a, b, c, mn, lg;
double d[10010];
bool v[10010];
Edge tmp, pqe;
priority_queue<Edge, vector<Edge>, greater<Edge> > pq;

void test();
void output(double);

int main() {
  cin >> n >> m >> s >> t;
  for (int i = 0; i <= n; ++i) d[i] = INF;
  for (int i = 0; i < m; ++i) {
    cin >> a >> b >> c;
    tmp.from = a;
    tmp.to = b;
    tmp.w = c;
    G[a].push_back(tmp);
  }
  d[s] = 1;
  pqe.from = s;
  pqe.w = 0;
  pq.push(pqe);
  while (!pq.empty()) {
    pqe = pq.top(); pq.pop();
    if (!v[pqe.from]) {
      v[pqe.from] = true;
      for (int i = 0; i < G[pqe.from].size(); ++i) {
        if (!v[G[pqe.from][i].to]) {
          if (d[G[pqe.from][i].to] > d[pqe.from] * G[pqe.from][i].w) {
            d[G[pqe.from][i].to] = d[pqe.from] * G[pqe.from][i].w;
            tmp.from = G[pqe.from][i].to;
            tmp.w = d[G[pqe.from][i].to];
            pq.push(tmp);
          }
        }
      }
    }
  }
  lg = floor(log10(d[t]));
  printf("%.2fe+%03d\n", d[t] / pow(10, lg), lg);
  // test();
  return 0;
}

void test() {
  double ans;
  while (cin >> ans) output(ans);
}

void output(double ans) {
  int l = floor(log10(ans));
  cout << "lg: " << l << endl;
  printf("%.2lfe+%03d\n", ans / pow(10, l), l);
}

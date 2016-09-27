#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#define PII pair<int, int>
#define INF 1e9
using namespace std;

vector<Edge> G[110];
int n, t, d[110];
bool v[110];
Edge tmp;
priority_queue<Edge, vector<Edge>, greater<Edge> > pq;

struct Edge {
  int from, to, w;
  bool operator > (const Edge& e) const {
    return w < e.w;
  }
};

int main() {
  while (cin >> n) {
    memset(v, false, sizeof(v));
    for (int i = 0; i < n; ++i) d[i] = INF;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        cin >> t;
        if (t != 0) {
          tmp.from = i;
          tmp.to = j;
          tmp.w = t;
          G[i].push_back(tmp);
          tmp.from = j;
          tmp.to = i;
          G[j].push_back(tmp);
        }
      }
    }
    v[0] = true;
    dis[0] = true;
    
  }
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int maxn = 1000 + 5;

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
int Kruskal();

int main() {
  ios_base::sync_with_stdio(false);
  cin >> T;
  while (T--) {
    cin >> N; E.clear();
    for (int i = 0; i < N; ++i) djs[i] = i;
    for (int i = 0; i < N; ++i) cin >> x[i] >> y[i];
    for (int i = 0; i < N; ++i) {
      for (int j = i + 1; j < N; ++j) {
        if (x[i] == x[j]) E.push_back((Edge){ i, j, abs(y[i] - y[j]) });
        if (y[i] == y[j]) E.push_back((Edge){ i, j, abs(x[i] - x[j]) });
      }
    }
    sort(E.begin(), E.end());
    cout << Kruskal() << '\n';
  }
  return 0;
}

inline int dis(int i, int j) {
  return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int F(int x) { return djs[x] == x ? x : djs[x] = F(djs[x]); }

int Kruskal() {
  int node = 1, ret = 0;
  for (auto e : E) {
    if (node == N) break;
    int st = F(e.st), ed = F(e.ed);
    if (st == ed) continue;
    ret += e.w;
    djs[st] = ed;
    node++;
  }
  return ret;
}

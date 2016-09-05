#include <deque>
#include <iostream>
#include <cstring>
using namespace std;

struct Edge {
  int from, to;
  int w;
};

deque<Edge> G[100000];
int c[100000];
bool v[100000];
int d;
void DFS(int, int, int);
int maxx;

int main() {
  int n, m, a, b;
  Edge temp;
  cin >> n >> m;
  maxx = 0;
  for (int i = 0; i < n; ++i) {
    cin >> c[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> a >> b;
    temp.from = a;
    temp.to = b;
    temp.w = c[b];
    G[a].push_back(temp);
    temp.from = b;
    temp.to = a;
    temp.w = c[a];
    G[b].push_back(temp);
  }
  memset(v, false, sizeof(v));
  cin >> d;
  int start = 0;
  v[start] = true;
  DFS(start, 1, 0);
  cout << maxx * 2 << endl;
  return 0;
}

void DFS(int x, int level, int cur) {
  int target;
  if (level > d) return;
  for (int i = 0; i < G[x].size(); ++i) {
    target = G[x][i].to;
    if (v[target]) continue;
    v[target] = true;
    cur += G[x][i].w;
    if (cur > maxx) maxx = cur;
    DFS(target, level + 1, cur);
  }
}
